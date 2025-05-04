#include "../template.h"
/**
 * Author: Václav Blažej
 * License: CC0
 * History:
 *   2025-04-20 Kruskal's and Prim's algorithm
 */

namespace kruskal{

#include "../data_structures/unionfind.cpp"

/** kruskal
 * Title: Minimum spanning tree (Kruskal's algorithm)
 * Description: Computes the spanning tree of a weighted graph
 * by merging components form shortest edges.
 * Sort can be replaced with radix/counting sort to get
 * better complexity with small weights.
 * Requires `union-find` data structure.
 */
struct Edge{
    ll f, t, w;
    bool operator<(const Edge &a)const { return w < a.w; }
};

vector<Edge> spanning(vector<vector<pair<ll,ll>>> &g){
    vector<Edge> e;
    for (ll i=0; i<g.size(); ++i) {
        for (pair<ll,ll> n : g[i]) {
            e.push_back({i,n.first,n.second});
        }
    }
    sort(e.begin(), e.end());
    Uf uf(g.size());
    vector<Edge> res;
    for (Edge &q : e) {
        if (uf.uni(q.f, q.t)) {
            res.push_back(q);
        }
    }
    return res;
}
/// kruskal
}

namespace prim{
/** prim
 * Title: Minimum spanning tree (Prim's algorithm)
 * Description: Build one component from shortest edges.
 */
struct Edge{
    ll f,t,w;
    bool operator<(const Edge&a)const{ return w>a.w; }
};
vector<Edge> spanning(vector<vector<pair<ll,ll>>> vert) {
    priority_queue<Edge> pq;
    vector<ll> group(vert.size(), 0);
    group[0] = 1;
    for (auto &p : vert[0]) {
        pq.push({0, p.first, p.second});
    }
    vector<Edge> res;
    while (!pq.empty()) {
        Edge e = pq.top(); pq.pop();
        if (group[e.t]) continue;
        group[e.t]=1;
        res.push_back(e);
        for (pair<ll,ll> n : vert[e.t]) {
            pq.push({e.t,n.first,n.second});
        }
    }
    return res;
}
/// prim
}

int main () {
    ll N, M; cin >> N >> M;
    vector<vector<pair<ll,ll>>> g(N);
    for(ll i=0; i<M; ++i){
        ll b, c, w; cin >> b >> c >> w;
        g[b].push_back({c,w});
        g[c].push_back({b,w});
    }
    vector<kruskal::Edge> res=kruskal::spanning(g);
    vector<prim::Edge> res2=prim::spanning(g);
    ll s=0,ss=0;
    for(auto &p : res) s+=p.w;
    for(auto &p : res2) ss+=p.w;
    assert(s==ss);
    cout<<s<<endl;
    return 0;
}
