#include "../../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-05 Added counting sort
 */


/** csort
 * Title: Counting sort
 * Description: Linear stable sorting for the case where elements values range from $0$ to $M$.
 * Time: $O(N+M)$, $N$ array size, $M$ elements universe
 */
void counting_sort(vector<ll> &a){
	ll M = *max_element(a.begin(), a.end())+1;
	ll N = a.size();
	vector<ll> c(M), r(N);
	for (ll i=0; i<N; ++i) ++c[a[i]];
	for (ll i=1; i<M; ++i) c[i] += c[i-1];
	for (ll i=N-1; i>=0; --i) r[--c[a[i]]] = a[i];
	a = r;
}
/// csort

#include "run.h"
int main(){
	return run(counting_sort);
}

