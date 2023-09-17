#include <bits/stdc++.h>

using namespace std;

#define es ios::sync_with_stdio(false);cin.tie(nullptr);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define randomizer mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define mst(v,k) memset((v),(k),sizeof(v));
 
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 2e5 + 7;
const int maxN = 21;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;
const double PI = acos(-1.);

int n,m;
array<int,maxik> rep;
array<int,maxik> depth;
array<array<int,maxN>,maxik> lca;
array<array<ll,maxN>,maxik> highest;
vector<vector<pii>> g;
ll ans{0};
int findik(int a);
array<int,maxik> sizes;
void unionik(int a, int b);
array<bool,maxik> used;
array<ll,maxik> res;
void dfs(int v = 1,int par = 0,int lvl = 0,ll val = 0);
ll LCA(int a,int b);
struct edge
{
    int u{0}; int v{0};
    ll val{};
    int indx{0};
    bool operator<(edge &e)
    {
        return this->val < e.val;
    }
};
array<edge,maxik> edges;
int main()
{
    es;
    cin >> n >> m;
    sizes.fill(1);
    iota(rep.begin()+1,rep.begin()+n+1,1);
    g.resize(n+1);
    for(int i{1};i<=m;i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].val;
        edges[i].indx = i;
    }
    sort(edges.begin()+1,edges.begin()+1+m);
    for(int i{1}; i<=m ;i++)
    {
        int u = findik(edges[i].v);
        int v = findik(edges[i].u);
        if( u != v)
        {
            unionik(u,v);
            ans += edges[i].val;
            g[edges[i].u].push_back(make_pair(edges[i].v,edges[i].val));
            g[edges[i].v].push_back(make_pair(edges[i].u,edges[i].val));
            used[i] = true;
        }
    }
    dfs();
    for(int k{1};k<maxN;k++)
    {
        for(int i{1};i<=n;i++)
        {
            lca[i][k] = lca[lca[i][k-1]][k-1];
            highest[i][k] = max(highest[i][k-1],highest[lca[i][k-1]][k-1]);
        }
    }
    for(int i{1};i<=m;i++)
    {
        if(used[i])
        {
            res[edges[i].indx] = ans;
        }
        else
        {
            ll result = LCA(edges[i].v,edges[i].u);
            res[edges[i].indx] = ans-result+edges[i].val;
        }
    }
    for(int i{1};i<=m;i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
int findik(int a)
{
    if(rep[a] != a)
    {
        rep[a] = findik(rep[a]);
    }
    return rep[a];
}
void unionik(int a,int b)
{
    if(sizes[a] > sizes[b])
    {
        swap(a,b);
    }
    rep[a] = b;
    sizes[b] += sizes[a];
    return;
}
void dfs(int v,int par,int lvl,ll val)
{
    lca[v][0] = par;
    highest[v][0] = val;
    depth[v] = lvl;
    for(auto u : g[v])
    {
        if(u.first == par)
        {
            continue;
        }
        dfs(u.first,v,lvl+1,u.second);
    }
}
ll LCA(int a, int b)
{
    ll result{0};
    if(depth[b] > depth[a])
    {
        swap(a,b);
    }
    for(int k = maxN-1; k>=0;k--)
    {
        if(depth[lca[a][k]] >= depth[b])
        {
            result = max(result,highest[a][k]);
            a = lca[a][k];
        }
    }
    if(a==b)
    {
        return result;
    }
    for(int k = maxN-1; k>=0;k--)
    {
       if(lca[a][k]!= lca[b][k])
       {
            result = max(result,max(highest[a][k],highest[b][k]));
            a=lca[a][k],b = lca[b][k];
       }
    }
    result = max(result,max(highest[a][0],highest[b][0]));
    return result;
}
