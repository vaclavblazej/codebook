#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-23 Added aho-corasick
 */

/** aho-corasick
 * Title: Multiple patterns search (Aho-Corasick)
 * Description: Given a set of patterns of total length $m$ we can query text of length $n$ to obtain all $r$ occurrences of the patterns in the text.
 * Time: $O(m+n+r)$
 */
struct Node {
	unordered_map<char, ll> next;
	ll fail = 0, sol = 0, final = -1;
};
struct Found {
	ll idx, pos;
};
struct AC {
	vector<Node> t;
	AC(vector<string> &a) : t(1) {
		for(ll i=0; i<a.size(); ++i){
			string &s = a[i];
			ll e = 0;
			for (char c : s) {
				if (!t[e].next.count(c)) {
					t[e].next[c] = t.size();
					t.push_back(Node());
				}
				e = t[e].next[c];
			}
			t[e].final = i;
		}
		queue<ll> q;
		for (auto p : t[0].next) {
			q.push(p.second);
		}
		while (!q.empty()) {
			ll el = q.front(); q.pop();
			for (auto p : t[el].next) {
				char c = p.first;
				ll child = p.second;
				q.push(child);
				t[child].fail = next(t[el].fail, c);
			}
		}
		q.push(0);
		while (!q.empty()) {
			ll el = q.front(); q.pop();
			for (auto p : t[el].next) {
				ll child = p.second;
				q.push(child);
				ll par = t[child].fail;
				while (par && t[par].final == -1) {
					par = t[par].fail;
				}
				t[child].sol = par;
			}
		}
	}
	ll next(ll id, char c) {
		while (id && !t[id].next.count(c)){
			id = t[id].fail;
		}
		return t[id].next.count(c) ? t[id].next[c] : id;
	}
	vector<Found> find(string &text) {
		vector<Found> res;
		ll cur = 0, up;
		for(ll i=0; i<text.size(); ++i){
			char c = text[i];
			up = cur = next(cur, c);
			if (up && t[up].final != -1) {
				res.push_back({t[up].final, i});
			}
			up = t[up].sol;
			while (up && t[up].final != -1) {
				res.push_back({t[up].final, i});
				up = t[up].sol;
			}
		}
		return res;
	}
};
/// aho-corasick


int main () {
	vector<string> needles = {
		"a",
		"ab",
		"bc",
		"bca",
		"c",
		"caa"
	};
	AC ac(needles);
	// for (ll i=0; i<ac.t.size(); ++i) {
		// Node &n = ac.t[i];
		// cout << "node " << i << ' ' << n.final << ' ' << n.fail << ' ' << n.sol << ' ' << endl;
		// for (auto p : n.next) {
			// cout << p.first << ' ' << p.second << endl;
		// }
	// }
	string text = "bacaabca";
	vector<Found> res = ac.find(text);
	cout << "Found in text '" << text << "':" << endl;
	for (Found &f : res) {
		cout << needles[f.idx] << " ending at " << f.pos << endl;
	}
	return 0;
}

