#include "../template.h"
typedef vector<vector<ll>> graph;
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-27 Added bipartite checker
 */

/** bipartite
 * Title: Bipartite checking
 * Description: Traverse the graph and either
 * determine its 2-coloring (returns `true`)
 * or find an odd cycle (returns `false`).
 * Time: $O(n+m)$
 */
pair<bool, vector<ll>> bipartite(graph &g) {
	ll N = g.size();
	vector<ll> c(N, 2), p(N, -1), s;
	for (ll i=0; i<N; ++i) {
		if (c[i] != 2) continue;
		s.push_back(i);
		c[i] = 0;
		while (!s.empty()) {
			ll u = s.back(); s.pop_back();
			for (ll n : g[u]) {
				if (c[n] == 2) {
					c[n] = 1-c[u];
					s.push_back(n);
					p[n] = u;
				} else if (c[n] == c[u]) {
					p[p[n]] = n;
					vector<ll> res(1, n);
					do {
						res.push_back(u);
						u = p[u];
					} while (n != u);
					return {false, res};
				}
			}
		}
	}
	return {true, c};
}
/// bipartite

int main(){
	ll N, M; cin >> N >> M;
	graph g(N);
	for (ll i=0; i<M; ++i) {
		ll f, t; cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	pair<bool,vector<ll>> res=bipartite(g);
	if (res.first) { // print the coloring
		cout << "Yes, is bipartite. Coloring is:\n";
		for (ll e:res.second) cout << e << ' ';
		cout << endl;
	} else {
		cout << "No, odd cycle of length ";
		cout << res.second.size();
		cout << " is:\n";
		for (ll e : res.second) cout << e << ' ';
		cout << endl;
	}
	return 0;
}
