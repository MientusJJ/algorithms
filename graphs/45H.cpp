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
const int maxik = 9e2 + 7;
const int maxN = 27;
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
int result{0};
int col{0};
vector<vector<int>> g,coloradj;
vector<pii> res;
bool visited[maxik];
void dfs1(int v,int par);
void dfs2(int v,int par);
bool hasRoad[maxik][maxik];
vector<int> low,depth,one,indx,color;
int main()
{
    es;
    scanf("%d %d",&n,&m);
    g.resize(n+1);
    low.resize(n+1);
    depth.resize(n+1);
    indx.resize(n+1);
    color.resize(n+1);
    coloradj.resize(n+1);
    dfs1(1,0);
    for(int i{0};i< m;i++)
    {
        int u,v;
        scanf("%d %d",&v,&u);
        if(hasRoad[u][v] || hasRoad[v][u])
        {
            continue;
        }
        g[v].push_back(u);
        g[u].push_back(v);
        hasRoad[u][v] = hasRoad[v][u] = true;
    }
    if(n<=2)
    {
        printf("%d\n",-1);
        return 0;
    }
    dfs1(1,0);
    mst(visited,0);
    dfs2(1,0);
    one.clear();
    // for(int i{1};i<=n;i++)
    // {
    //     printf("depth: %d, low: %d, color: %d\n",depth[i],low[i],color[i]);
    // }
    for(int i=1;i<=n;i++)
    {
        for(auto u : g[i])
        {
            if(color[i] != color[u])
            {
                coloradj[color[i]].push_back(color[u]);
               //printf("%d :: %d\n",color[i],color[u]);
            }
        }
    }
    for(int i=1;i<=col;i++)
    {
        if(coloradj[i].size()==1)
        {
            one.push_back(i);
        }
    }
    printf("%d\n",int((one.size()+1)/2));
    for(int i=0;i<int(one.size()+1)/2;i++)
    {
        int left = one[i];
        int right = one[min(one.size()-1,i+one.size()/2)];
        printf("%d %d\n",indx[left],indx[right]);
    }

}
void dfs1(int v,int par)
{
    visited[v] = true;
    depth[v] = depth[par]+1;
    for(auto u : g[v])
    {
        if(!visited[u])
        {
            dfs1(u,v);
        }
    }
}
void dfs2(int v,int par )
{
    visited[v] = true;
    low[v] = depth[v];
    one.push_back(v);
    for(auto u : g[v])
    {
        if(!visited[u])
        {
            dfs2(u,v);
            low[v] = min(low[v],low[u]);
        }
        else if (u !=par)
        {
            low[v] = min(low[v],depth[u]);
        }
    }
    if(low[v] == depth[v])
    {
        col++;
        indx[col] = one.back();
        while(!one.empty())
        {
            int x = one.back();
            one.pop_back();
            color[x] = col;
            if(x==v) break;
        }
    }
}
