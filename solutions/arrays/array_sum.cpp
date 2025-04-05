#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 */

/** array_sum
 * Title: Offline array sum queries
 * Description: Preprocess array to quickly answer sum queries for numbers
 * from `f` (inclusive) to `t` (exclusive). The prefix sum `d` contains on
 * `i` sums of elments on indices smaller than `i`.
 * Time: prepare $O(N)$, sum $O(1)$
 */
#define MX 1000004
ll d[MX];
ll sum(ll f, ll t){
	return d[t] - d[f];
}
void prepare(ll N){
	for(ll x=1; x<=N; ++x) d[x] += d[x-1];
}
/// array_sum

int main() {
	for(int x=0; x<MX; ++x){ d[x]=0; }
	ll N;cin>>N;
	for(int x=1; x<=N; ++x){ cin>>d[x]; }
	prepare(N);
	return 0;
}

