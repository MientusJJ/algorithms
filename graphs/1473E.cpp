#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <string>
#include <cmath>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <fstream>
#include <chrono>
#include <random>
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
//#define TXTcreate freopen("C:/Temp/output.txt","w",stdout);freopen("input.txt","w",stdout);
#define txt  freopen("C:/Temp/input.txt","r",stdin); freopen("C:/Temp/output.txt","w",stdout);
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
const int maxik = 3e5 + 7;
const int maxN = 1 << 19;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;


vector<vector<pll>> g;
vector<ll> ans;
vector<bool> vis;
int n, m;
void dijk(int s);
void addEdge(ll u, ll v, ll w);
int main()
{
	es;
	//txt;
	cin >> n >> m;
	g.resize(n*4 + 1);
	vis.resize(n*4 + 1, false);
	ans.resize(n*4 + 1, INFll);
	ans[0] = ans[1] = 0;
	for (int i = 1; i <= m; i++)
	{
		ll u, v,w;
		cin >> u >> v >> w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	dijk(1);
	for (int i = 2; i <= n; i++)
	{
		cout << ans[i+3*n] << " ";
	}
	cout << endl;
	return 0;
}
void addEdge(ll u, ll v, ll w)
{
	g[u].push_back({ v,w });
	g[u + 1 * n].push_back({ v + 1 * n,w });
	g[u + 2 * n].push_back({ v + 2 * n,w });
	g[u+3*n].push_back({ v+3*n,w });
	g[u ].push_back({ v + 1 * n,2*w });
	g[u].push_back({ v + 2 * n,0 });
	g[u + 1 * n].push_back({ v + 3 * n,0 });
	g[u + 2 * n].push_back({ v + 3 * n, 2 * w });
	g[u].push_back({ v + 3 * n,w });
	return;
}
void dijk(int s)
{
	struct compadre
	{
		bool operator()(const pll &a, const pll &b)
		{
			return a.second > b.second;
		}
	};
	priority_queue<pll, vector<pll>, compadre> q;
	for (int i = 0; i < g[s].size(); i++)
	{
		q.push(g[s][i]);
	}
	while (!q.empty())
	{
		ll v = q.top().first;
		ll dis = q.top().second;
		q.pop();
		if (!vis[v])
		{
			vis[v] = 1;
			ans[v] = min(ans[v], dis);
			for (int i = 0; i < g[v].size(); i++)
			{
				q.push({g[v][i].first, g[v][i].second + ans[v]});
			}
		}
	}
}
