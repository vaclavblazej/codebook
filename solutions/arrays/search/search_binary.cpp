#include "../template.cpp"
/**
 * Author: Václav Blažej
 * License: CC0
 * Title: Binary search
 * Description: Returns the first TRUE value.
 */

/** lsearch
 * Description: Low is one above FALSE, high is on TRUE.
 */
ll bsearch(ll low, ll high, bool(*cmp)(ll)){
	ll mid;
	while (low < high) {
		mid = (low+high)/2;
		if (cmp(mid)) high = mid;
		else          low = mid+1;
	}
	return low;
}
/// lsearch

/** dsearch
 * Description: A variant for floating point values.
 */
ld bsearch(ld low, ld high, bool(*cmp)(ld)){
	ld mid;
	while (low < high-EPS) {
		mid = (low+high)/2;
		if (cmp(mid)) high = mid;
		else          low = mid+EPS;
	}
	return mid;
}
/// dsearch

ll M;

// comp
// example comparison function
bool comp(ll val){
	return (val*(val+1))/2 >= M;
}
/// comp

bool test(ld val){
	return val*val>=2;
}

int main(){
	cout << "sqrt of 2 is: " << bsearch(0.,2.,comp) << endl;
}
