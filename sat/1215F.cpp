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
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define Y cout << "YES" << "\n";
#define N cout << "NO" << "\n";
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxik = 2e6;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
vector<vector<int> >g;
vector<vector<int> > g_adj;
vector<int> L;
vector<int> R;
stack <int> stk;
vector<int> comp;
vector<bool> vis;
vector<int> res;
void dfs1(int v);
void dfs2(int v, int con);
int n, p, M, m;
int counter = 0;
void addEdge(int u, int v);
int freq = 0;
void kosaraju();
int main()
{
	es;
	cin >> n >> p >> M >> m;
	int eth = p * 2 + M * 2 + 5;
	int t = p * 2;
	g.resize(maxik);
	g_adj.resize(maxik);
	vis.resize(maxik, false);
	comp.resize(maxik, -1);
	L.resize(p + 1, 0);
	R.resize(p + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		addEdge(u * 2 | 1, v * 2);
		addEdge(v * 2 | 1, u * 2);
	}
	for (int i = 1; i <= p; i++)
	{
		cin >> L[i] >> R[i];
		addEdge(i * 2, t + (R[i] * 2)+2);
		addEdge(i * 2, t + (L[i] * 2) | 1);
		addEdge(t + (R[i] * 2)+2 | 1, i * 2 | 1);
		addEdge(t + (L[i] * 2), i * 2 | 1);
	}
	++t;
	for (int i = 1; i < 2 * (M - 1); i += 2)
	{
		addEdge(t + i, t + i + 2);
		addEdge(t + i + 3, t + i + 1);
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		addEdge(v * 2, u * 2 | 1);
		addEdge(u * 2, v * 2 | 1);
	}
	kosaraju();
	return 0;
}
void addEdge(int u, int v)
{
	g[u].push_back(v);
	g_adj[v].push_back(u);

	return;
}
void kosaraju()
{
	for (int i = 2; i < g.size(); i++)
	{
		if (!vis[i])
		{
			dfs1(i);
		}
	}
	while (stk.size())
	{
		int v = stk.top();
		stk.pop();
		if (comp[v] == -1)
		{
			dfs2(v, ++counter);
		}
	}
	for (int i = 2; i < 2 * (p + 1); i += 2)
	{
		if (comp[i] == comp[i + 1])
		{
			cout << "-1\n";
			return;
		}
		if (comp[i] > comp[i + 1])
		{
			res.push_back(i / 2);
			freq = max(freq, L[i / 2]);
		}
	}
	cout << res.size() << " " << freq << "\n";
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << "\n";
	return;
}
void dfs1(int v)
{
	vis[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if (!vis[u])
		{
			dfs1(u);
		}
	}
	stk.push(v);
}
void dfs2(int v, int cnt)
{
	comp[v] = cnt;
	for (int i = 0; i < g_adj[v].size(); i++)
	{
		int u = g_adj[v][i];
		if (comp[u] == -1)
		{
			dfs2(u, cnt);
		}
	}
	return;
}
