#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-10 Added eratosthenes and factorization
 *   2025-04-11 Added sumdivisors
 */

/** eratosthenes
 * Title: Find prime numbers (Sieve of Eratosthenes)
 * Description: Computes the biggest factor for every number from 1 to `upto-1`.
 * Returns the sorted list of primes from 1 to `upto-1`.
 * Time: $O(n \log \log n)$
 */
vector<ll> fac; // highest prime factor of i
vector<ll> erat(ll upto) {
	fac = vector<ll>(upto, 0);
	vector<ll> primes;
	fac[0] = fac[1] = 1;
	for (ll i=2; i<upto; ++i) {
		if (fac[i] != 0) continue;
		primes.push_back(i);
		for (ll j=i; j<upto; j+=i) fac[j] = i;
	}
	return primes;
}
/// eratosthenes

/** factorization
 * Title: Prime Factorization
 * Description: Requires *eratosthenes* to be run with `upto > n`.
 * Returns the vector of (factor, multiplicity) pairs sorted from the biggest.
 * Time: $O({\rm result})$
 */
vector<pair<ll,ll>> fact(ll n){
	vector<pair<ll,ll>> r;
	while (n > 1) {
		ll v = fac[n], c = 0;
		while (fac[n] == v) {
			++c;
			n /= v;
		}
		r.push_back({v,c});
	}
	return r;
}
/// factorization


/** sumdivisors
 * Title: Sum of divisors
 * Description: Requires *factorzation* and *eratosthenes* to be run with `upto > n`.
 * Returns the total sum of all the divisors of $n$, including $1$ and $n$ itself.
 * Time: $O({\rm factorization})$
 */
ll sumdivisors(ll n){
	vector<pair<ll,ll>> f = fact(n);
	ll res=1;
	for (pair<ll,ll> p : f) {
		res *= (pow(p.first,p.second+1)-1)/(p.first-1);
	}
	return res;
}
/// sumdivisors


int main() {
	ll MX=16000007;
	cout << "computing eratosthenes" << endl;
	vector<ll> primes=erat(MX);
	cout << "eratosthenes complete" << endl;
	cout << "write numbers up to " << MX-1 << " to be factorized:" << endl;
	while(true){
		ll N; cin >> N;
		if(N >= MX) {
			cout << "number is too big" << endl;
			continue;
		}
		if(!cin.good()) break;
		vector<pair<ll,ll>> r = fact(N);
		cout << "factorization of " << N << " is:\n";
		for(auto w:r) cout << w.first << '^' << w.second << ' ';
		cout<<endl;
        cout << "sum of its divisors (including N) is " << sumdivisors(N) << endl;
	}
	return 0;
}
