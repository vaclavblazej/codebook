#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-26 Added the search
 * Description: solves https://codeforces.com/contest/2098/problem/D
 */

ll mod = 1000000007ll;
ll d(ll val){ return val%mod; }

struct Pt{
    ll x, y;
    bool operator<(const Pt&other)const{
        return (x!=other.x)?(x<other.x):(y<other.y);
    }
    bool operator==(const Pt&other)const{
        return x==other.x && y==other.y;
    }
};
ostream& operator<<(ostream&os, const Pt &p){
    os<<'('<<p.x<<','<<p.y<<')';
    return os;
}

typedef vector<vector<ll>> graph;

/** cycletrees
 * Title: Cycle trees
 * Description: Goes through the graph and for each component identifies
 * its number of loops and lower bound on the number of cycles -- this count
 * is precise only if the cycles are edge disjoint. Loops are assumed to
 * create two incidencies in the graph.
 */
struct Res{
    ll size, cycles, loops;
};
vector<Res> search(graph &g) {
    vector<Res> res;
    set<ll> visited;
    for (ll i=0; i<g.size(); ++i) {
        if (!visited.insert(i).second) continue;
        queue<ll> q; q.push(i);
        ll size = 0, cycles = 0, loops = 0;
        while (!q.empty()) {
            ll e = q.front(); q.pop();
            ++size;
            for (ll &n : g[e]) {
                if (n == e) {
                    ++loops;
                } else if (visited.insert(n).second) {
                    q.push(n);
                } else {
                    ++cycles;
                }
            }
        }
        res.push_back({size,(cycles-size+1)/2,loops/2});
    }
    return res;
}
/// cycletrees

ll explore(graph &g){
    ll res = 1;
    auto w = search(g);
    for(Res r : w){
        if(r.cycles+r.loops >= 2){
            res=0;
            continue;
        }else if(r.loops == 1){
            continue;
        }else if(r.cycles == 1){
            res=d(res*2);
        }else{
            res=d(res*r.size);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        vector<Pt> a(k+1);
        for(Pt&e:a)cin>>e.x>>e.y;
        graph g;
        bool ok=true;
        set<Pt> taken;
        for(Pt&q:a){
            if(taken.count(q)) ok=false;
            taken.insert(q);
        }
        for(ll i=0; i<a.size()-1; ++i){
            Pt f=a[i], t=a[i+1];
            ll dist=abs(f.x-t.x)+abs(f.y-t.y);
            if(dist!=2){
                ok=false;
            }
        }
        if(a.size()<=1){ cout<<1<<endl; continue; }
        if(!ok){ cout<<0<<endl; continue; }
        map<Pt,ll> nodemap;
        for(ll i=0; i<a.size()-1; ++i){
            Pt f=a[i], t=a[i+1];
            Pt q,w;
            if(f.x == t.x){
                w=q={f.x,(f.y+t.y)/2};
                if(taken.count(q)) ok=false;
                taken.insert(q);
            } else if(f.y == t.y){
                w=q={(f.x+t.x)/2,f.y};
                if(taken.count(q)) ok=false;
                taken.insert(q);
            } else {
                q = {f.x,t.y};
                w = {t.x,f.y};
            }
            if(!nodemap.count(q)){ nodemap[q]=g.size(); g.push_back(vector<ll>()); }
            if(!nodemap.count(w)){ nodemap[w]=g.size(); g.push_back(vector<ll>()); }
            g[nodemap[q]].push_back(nodemap[w]);
            g[nodemap[w]].push_back(nodemap[q]);
        }
        if(!ok){ cout<<0<<endl; continue; }
        cout<<explore(g)<<endl;
    }
    return 0;
}
