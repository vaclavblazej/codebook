#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-27 Added the Chinese remainder theorem
 */
#define MAIN
#include "gcd.cpp"

/** remainder
 * Title: Chinese remainder theorem
 * Description: Takes a list of $(r_i, m_i)$, returns the unique
 * solution $x$ for which $x \equiv r_i \mod m_i$ for each $i$.
 * Requires `extendedgcd`.
 */
ll remainder(vector<pair<ll,ll>> &a) {
	ll x, y, g, f, s, res=0, md=1;
	for (auto p : a) {
		tie(f, s) = p;
		tie(g, x, y) = egcd(md, s);
		res = res*s*y + f*md*x;
		md *= s;
	}
	res = ((res%md)+md)%md;
	return res;
}
/// remainder

int main(){
	vector<pair<ll,ll>> a;
	a.push_back({2,3});
	a.push_back({3,5});
	a.push_back({2,7});
	cout << remainder(a) << endl;
	return 0;
}

