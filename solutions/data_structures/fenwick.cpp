#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-05 Added Fenwick tree
 */


/** fenwick
 * Title: Fenwick tree
 * Description: Quick update of single elements and range sum queries.
 * Time: $O(\log n)$ update, $O(\log n)$ prefsum, (optional) $O(n)$ create
 * (alt. insert one by one)
 */
#define lsb(n) (n & -n)
struct Fenwick{
	vector<ll> fw;
	Fenwick(ll N) : fw(N+1,0) {};
	ll prefsum(ll n) { // inclusive
		n++;
		ll sum = 0;
		while (n > 0) {
			sum += fw[n];
			n -= lsb(n);
		}
		return sum;
	}
	void update(ll n, ll v) {
		n++;
		while (n < fw.size()) {
			fw[n] += v;
			n += lsb(n);
		}
	}
	// optional functions below
	ll sum_range(ll i, ll j) { // inclusive
		return prefsum(j) - prefsum(i-1);
	}
	Fenwick(vector<ll> &a) : fw(a.size()+1, 0) {
		for(ll i=0; i<a.size(); ++i) {
			fw[i+1]=a[i];
		}
		for(ll i=1; i<a.size()+1; ++i){
			ll p = i+lsb(i);
			if (p <= fw.size()) {
				fw[p] += fw[i];
			}
		}
	}
};
/// fenwick

ll slow_check(vector<ll> &a, ll idx){
	ll sum = 0;
	for(ll i=0; i<idx; ++i){
		sum += a[i];
	}
	return sum;
}

int main(){
	srand(time(NULL));
	ll N=100;
	ll MX=100000,C=10000000;
	vector<ll> check(N,0);
	for(ll i=0; i<100; ++i){
		ll idx=rand()%N;
		ll inc=(rand()%MX)-MX/2;
		check[idx] += inc;
	}
	Fenwick f(check);
	for(ll i=0; i<C; ++i){
		ll idx=rand()%N;
		ll inc=(rand()%MX)-MX/2;
		f.update(idx, inc);
		check[idx]+=inc;
		if(!(f.prefsum(idx)==slow_check(check,idx))){
			cout<<i<<" th step: "<<f.prefsum(idx)<<' '<<slow_check(check,idx)<<endl;
			assert(f.prefsum(idx)==slow_check(check,idx));
		}
	}
	return 0;
}
