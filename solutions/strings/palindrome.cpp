#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-27 Added Manacher's algorithm
 */

/** manacher
 * Title: Palindromes (Manacher's algorithm)
 * Description: Returns an array that describes width of
 * a palindrome centered at that position. Note that each
 * letter and each mid-point between letters is a position.
 * E.g. for aabbaa we have `| a | a | b | b | a | a |` and
 * the result is `0 1 2 1 0 1 6 1 0 1 2 1 0`.
 * Time: $O(n)$
 */
vector<ll> manacher(string text){
	ll N = 2*text.length() + 1;
	vector<ll> res(N,0);
	if (N == 1) return res;
	res[1] = 1;
	ll C = 1, R = 2;
	ll diff = -1;
	for (ll i=2; i<N; ++i) {
		res[i] = 0;
		diff = R-i;
		if (diff > 0) res[i] = min(res[2*C-i], diff);
		ll l = i-res[i], r = i+res[i];
		while (l>0 && r<N &&
				(((r+1)%2 == 0) ||
				 (text[(r+1)/2] == text[(l-1)/2]))) {
			++res[i];
			++r;
			--l;
		}
		if (r > R) {
			C = i;
			R = r;
		}
	}
	return res;
}
/// manacher

void test(string str, vector<ll> expect){
	vector<ll> res=manacher(str);
	assert(res.size()==expect.size());
	for (ll i=0; i<res.size(); ++i) {
		assert(res[i]==expect[i]);
	}
	cout << "test ok: " << str << " => ";
	for (ll i=0; i<res.size(); ++i) {
		cout << res[i]<<' ';
	}
    cout<<endl;
}

int main(){
	test("", {0});
	test("a", {0,1,0});
	test("aabbaa", {0,1,2,1,0,1,6,1,0,1,2,1,0});
	test("ababbaa", {0,1,0,3,0,3,0,1,4,1,0,1,2,1,0});
	test("abcbaaa", {0,1,0,1,0,5,0,1,0,1,2,3,2,1,0});
	return 0;
}
