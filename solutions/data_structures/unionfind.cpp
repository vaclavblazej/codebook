#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-21 Added union-find data structure
 */

/** unionfind
 * Title: Union-find (Disjoint set union)
 * Description: Keeps a family of disjoint sets and allows us to
 * make their `union` and `find` which set an element belongs to.
 * Keeps connected components in graphs when edges can be only added.
 */
struct Uf{
	vector<ll> p, r; // p=element's parent, r=rank
	Uf(ll n) : p(n), r(n) {
		iota(p.begin(), p.end(), 0);
	}
	ll find(ll a) {
		return p[a]==a ? a : p[a]=find(p[a]);
	}
	bool uni(ll a, ll b) {
		a = find(a);
		b = find(b);
		if (a==b) return false;
		if (r[a] < r[b]) swap(a, b);
		p[b] = a;
		r[a] += r[a]==r[b];
		return true;
	}
	bool same(ll a, ll b) {
		return find(a) == find(b);
	}
};
/// unionfind
