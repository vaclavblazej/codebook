#include "../template.h"


#define INF (1ll<62)
#define EPS 1e-8
/** ternary
 * Title: Ternary search
 * Description: Find extrem (minimum) for a convex function.
 */
ll ternary(ll mn, ll mx, ll(*getVal)(ll)){
	ll low=mn, high=mx, lm, hm, last=INF;
	while (true) {
		lm = low+(high-low)/3;
		hm = low+(high-low)*2/3;
		if (lm >= hm) break;
		if (getVal(lm) < getVal(hm)) {
			high = hm;
		} else {
			low = lm+1;
		}
		last = lm;
	}
	return low;
}
/// ternary

/** dternary
 * for floating point values
 */
ld ternary(ld mn, ld mx, ld(*getVal)(ld)){
	ld low=mn, high=mx, lm, hm, last=INF;
	while (true) {
		lm = low+(high-low)/3;
		hm = low+(high-low)*2/3;
		if (lm >= hm) break;
		if (getVal(lm) < getVal(hm)) {
			high = hm-EPS;
		} else {
			low = lm+EPS;
		}
		last = lm;
	}
	return low;
}
/// dternary

ld getVal(ld val){
	return val<10;
}

ll D,K,A,B,T;

ll getVal(ll val){
	ll j=min(D,K*val);
	ll h=D-j;
	// cout << (val-1)*T << ' ' << A*j << ' '<<h*B << "   ";
	ll res = max(0ll,(val-1))*T+A*j+h*B;
	// cout << val << ' ' << h<< ' ' << res << endl;
	return res;
}
