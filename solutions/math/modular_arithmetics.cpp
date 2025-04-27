#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-11 Added sumdivisors
 */


const ll mod = 1000000007ll; // prime

/** powmod
 * Title: Powers and inverses in modulo
 * Description: Quickly determine power of a number in modulo $b^p \bmod mod$
 * or its inverse $b^{-1} \bmod mod = b^{mod-2} \mod mod$.
 * Time: powermod $O(\log p)$, modinv $O(\log mod)$
 */
ll powermod(ll b, ll p) {
	ll r = 1;
	b %= mod;
	while (p > 0) {
		if (p & 1) r = (r*b)%mod;
		p /= 2;
		b = (b*b)%mod;
	}
	return r;
}
ll modinv(ll b) {
	return powermod(b, mod-2);
}
/// powmod

/** combmod
 * Title: Combinations in modulo
 * Description: After calling `precompute` value `F[i]` is the factorial of `i`,
 * and `I[i]` is the inverse of the factorial of `i`. This allows us to compute
 * combination number in constant time. Requires *modinv*.
 * Time: precompute $O(2 \cdot upto)$, comb $O(1)$
 */
ll d(ll n) { return n % mod; }
vector<ll> F, I;
ll comb(ll x, ll y) {
	return d(d(F[x] * I[y]) * I[x - y]);
}
void precompute(ll upto, ll mod){
	F = I = vector<ll>(upto);
	F[0] = 1;
	for(ll i=0; i<upto; ++i) {
		F[i+1] = d(F[i] * (i+1));
	}
	I[upto-1] = modinv(F[upto-1]);
	for(ll i=upto-2; i>=0; --i) {
		I[i] = d(I[i+1] * (i+1));
	}
}
/// combmod


int main () {
	ll MX=3000000;
	cout << "precomputing" << endl;
	precompute(MX, mod);
	ll mod = 1000000007ll;
	ll a, b;
	cout << "input pairs for which you want combinations computed";
	cout << "(modulo " << mod << ")" << endl;
	while (cin >> a >> b) {
		if ( a >= MX || b >= MX ) {
			cout << "precomputed only upto " << MX << ", ";
			cout << "parameters need to be smaller" << endl;
			continue;
		}
		if ( a < b ) {
			cout << "first parameter ought to be at least the second" << endl;
			continue;
		}
		cout << "there are " << comb(a, b) << " ways of chosing ";
		cout << b << " out of " << a << " elements" << endl;
	}
	return 0;
}

