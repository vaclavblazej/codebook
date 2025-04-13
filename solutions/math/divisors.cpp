#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-11 Added brute-force for finding divisors
 */

/** divisors
 * Title: Divisors
 * Description: Returns a list of sorted divisors of $n$.
 * Time: $\sqrt{n}$
 */
vector<ll> divisors(ll n) {
	vector<ll> a, b;
	for (ll i = 1; i <= (n+i-1)/i; ++i) {
		if (n%i == 0) {
			a.push_back(i);
			b.push_back(n/i);
		}
	}
	if (b.back()==a.back()) b.pop_back();
	a.insert(a.end(), b.rbegin(), b.rend());
	return a;
}
/// divisors

int main(){
	ll n;
	while(cin >> n){
		auto r = divisors(n);
		for(ll q : r) cout << q << ' ';
		cout << endl;
	}
	return 0;
}
