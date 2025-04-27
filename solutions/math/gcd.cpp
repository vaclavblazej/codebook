#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-10 Added short gcd and lcm
 *   2025-04-11 Added extended Euclidean algorithm
 */

/** shortgcdlcm
 * Title: GCD & LCM
 * Description: Compute the greatest common divisor or least common multiple
 * of numbers $a$ and $b$. Note that `gcd` (or `__gcd` before `c++17`) is a
 * library function.
 * Time: $O(\log(a+b))$
 */
ll gcd(ll a, ll b) {
	while (a) swap(b%=a, a);
	return b;
}
ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}
/// shortgcdlcm

/** extendedgcd
 * Title: Extended Euclidean algorithm
 * Description: Additionally to `gcd` it also computes $x,y$ such that
 * $ a\cdot x + b \cdot y = {\rm gcd}(a,b)$, i.e., Bézout's coefficients.
 * Time: $O(\log(a+b))$
 */
tuple<ll,ll,ll> egcd(ll a, ll b) {
	ll oldr = a, r = b;
	ll olds = 1, s = 0;
	ll oldt = 0, t = 1;
	while (r != 0) {
		ll q = oldr / r;
		tie(oldr, r) = tuple(r, oldr - q*r);
		tie(olds, s) = tuple(s, olds - q*s);
		tie(oldt, t) = tuple(t, oldt - q*t);
	}
	return tuple(oldr, olds, oldt);
}
/// extendedgcd

int main(){
	ll a, b;
	while (cin >> a >> b) {
		assert(__gcd(a,b) == gcd(a,b));
		cout << "gcd of " << a << " and " << b << " is: " << gcd(a,b) << endl;
		ll g, s, t;
		tie(g, s, t) = egcd(a, b);
		cout << "and their Bezout's coefficients are " << s << " and " << t;
		cout << ", hence " << s << "*" << a << " + " << t << "*" << b << " = " << g << endl;
	}
	return 0;
}
