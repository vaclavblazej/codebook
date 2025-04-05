#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 */

namespace basis{
/** basis
 * Title: Dynamic programming
 * Description: A generic approach to applying function result memorization.
 * Its application turns this example into the next one.
 */
ll fac(ll a, ll b){
	if (a < 3 || b < 3) return a+b;
	return fac(a-1, b) + fac(a, b-1);
}
/// basis
}

// dp
map<tuple<ll,ll>,ll> dp;
ll fac(ll a, ll b){
	auto res = dp.find({a,b});
	if(res != dp.end()) return res->second;
	if (a < 3 || b < 3) return dp[{a,b}] = a+b;
	return dp[{a,b}] = fac(a-1, b) + fac(a, b-1);
}
/// dp

