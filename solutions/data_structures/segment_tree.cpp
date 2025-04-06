#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-06 Added Segment tree
 */

/** segtree
 * Title: Range minimum query & element set
 * Description: Short segment tree with only set element and
 * range minimum query for inclusive-exclusive range [l, r).
 * Time: set $O(\log n)$, sum $O(\log n)$
 */
struct SegmentTree {
	ll N;
	vector<ll> a;
	SegmentTree(ll N) : N(N), a(2*N) {}
	void set(ll i, ll v) {
		i += N;
		a[i] = v;
		while (i /= 2) {
			a[i] = min(a[2*i], a[2*i+1]);
		}
	}
	ll sum(ll l, ll r) { // inc exc
		ll s = numeric_limits<ll>::max();
		l += N;
		r += N;
		while (l < r) {
			if (l&1) s = min(s, a[l++]);
			if (r&1) s = min(s, a[--r]);
			l /= 2;
			r /= 2;
		}
		return s;
	}
};
/// segtree

ll slow_check(vector<ll> &a, ll l, ll r){
	ll mn = numeric_limits<ll>::max();
	for(ll i=l; i<r; ++i){
		mn = min(mn, a[i]);
	}
	return mn;
}

int main(){
	srand(time(NULL));
	ll N=1000;
	ll MX=100000,C=1000000;
	vector<ll> check(N,0);
	for(ll i=0; i<100; ++i){
		ll idx=rand()%N;
		ll inc=(rand()%MX)-MX/2;
		check[idx] += inc;
	}
	SegmentTree st(N);
	for(ll i=0; i<N; ++i){
		st.set(i, check[i]);
	}
	for(ll i=0; i<C; ++i){
		ll idx=rand()%N;
		ll val=(rand()%MX)-MX/2;
		st.set(idx, val);
		check[idx]=val;
		ll l=rand()%N;
		ll r=rand()%N;
		if(l>r)swap(l,r);
		if(!(st.sum(l, r)==slow_check(check,l,r))){
			cout<<i<<" th step: "<<st.sum(l, r)<<' '<<slow_check(check,l,r)<<endl;
			assert(st.sum(l,r)==slow_check(check,l,r));
		}
	}
	return 0;
}
