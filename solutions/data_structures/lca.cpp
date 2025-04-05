#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 */

/** lca
 * Title: Lowest common ancestor (LCA)
 * Description: Given tree structure (by the list of parents where the root
 * loops) allows queries answering lowest common ancestor.
 * Gives -1 for distinct trees.
 * Time: create $O(N \log N)$, queries $O(\log N)$
 */
ll LOG=30; // must be more than log2(par.size())
struct LCA {
	ll N;
	vector<vector<ll>> dp; // binary lifting
	vector<ll> depth; // depth
	LCA(vector<ll> &par) : N(par.size()),
	depth(N, 1), dp(N, vector<ll>(LOG, -1)) {
		for (ll i=0; i<N; ++i) dp[i][0] = par[i];
		for (ll j=1; j<LOG; ++j) {
			vector<ll> tmp=depth;
			for (ll i=0; i<N; ++i) {
				dp[i][j] = dp[dp[i][j-1]][j-1];
				if (dp[i][j]!=dp[i][j-1]) {
					depth[i] += tmp[dp[i][j-1]];
				}
			}
		}
		for(ll i=0; i<N; ++i){
			if(dp[i][0]==i)--depth[i];
		}
	}
	ll lca(ll p, ll q) {
		if (depth[p] < depth[q]) swap(p, q);
		for(ll i=LOG-1; i>=0; --i){
			if (depth[p] - (1<<i) >= depth[q]){
				p = dp[p][i];
			}
		}
		if (p==q) return p;
		if (dp[p][LOG-1] != dp[q][LOG-1]) {
			return -1; // if we allow forests
		}
		for(ll i=LOG-1; i>=0; --i){
			if (dp[p][i] != dp[q][i]){
				p = dp[p][i];
				q = dp[q][i];
			}
		}
		return dp[p][0];
	}
};
/// lca

ll slow_check(vector<ll> &par, ll aa, ll bb){
	vector<ll> p, q;
	ll a=aa,b=bb;
	while(true) { p.push_back(a); if(a==par[a])break; a=par[a]; }
	while(true) { q.push_back(b); if(b==par[b])break; b=par[b]; }
	reverse(p.begin(), p.end());
	reverse(q.begin(), q.end());
	ll N=min(q.size(),p.size());
	// for(ll e:p)cout<<e<<' ';cout<<endl;
	// for(ll e:q)cout<<e<<' ';cout<<endl;
	ll ans = -1, i;
	for(i=0; i<N; ++i){
		if(q[i]!=p[i])break;
		ans=p[i];
	}
	// cout << "Q: " << aa << ' ' << bb << ", depth: " << i << ", ans: " << ans << endl;
	return ans;
}

int main(){
	ll N=100000, Q=100000;
	vector<ll> par(N);
	for(ll i=1; i<N; ++i){
		par[i]=rand()%i;
	}
	LCA w(par);
	for(ll i=0; i<Q; ++i){
		ll a=rand()%N;
		ll b=rand()%N;
		ll ra = w.lca(a, b);
		ll rb = slow_check(par, a, b);
		if(ra != rb){
			cerr << ra << ' ' << rb << endl;
			assert(ra == rb);
		}
	}
	return 0;
}
// use of lca principle in CF 702E
