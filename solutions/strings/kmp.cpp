#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-27 Added KMP
 */

/** kmp
 * Title: Single pattern search (Knuth-Morris-Pratt)
 * Description: Finds all occurrences of a pattern `p` in a text `t`.
 * Precomputation can be reused `KMP k(p); k.find(t)`.
 * Returns the list of text indices where the pattern starts.
 * Time: $O(n+m)$
 */
struct KMP {
	string p;
	vector<ll> back;
	KMP(string p) : p(p), back(p.size()+1) {
		back[0] = -1;
		ll i = 0, j = -1;
		while (i < p.size()-1) {
			while (j != -1 && p[i] != p[j]) {
				j = back[j];
			}
			back[i] = (p[++i]==p[++j]) ? back[j] : j;
		}
	}
	vector<ll> find(string& t) {
		ll i = 0, j = 0;
		vector<ll> res;
		while (j < t.size()) {
			while (i > -1 && p[i] != t[j]){
				i = back[i];
			}
			++j;
			if (++i >= p.size()) {
				res.push_back(j - i);
				i = back[i];
			}
		}
		return res;
	}
};
/// kmp

int main(){
	string t = "110100001011100000110110110011101010011001001011110001100101001111101101111110011011001101010110000000001111001010111110100110000001011000110010110001111010111011000101011000101101";
	string p = "1010110";
	KMP kmp(p);
	cout << "back array: ";
	for (ll w : kmp.back) cout << w << ' '; cout << endl;
	vector<ll> res = kmp.find(t);
	cout << "found " << res.size() << " occurrences on positions:" << endl;
	for (ll n : res) {
		string occurrence = t.substr(n, p.size());
		cout << n << " which contains " << occurrence << endl;
	}
}
