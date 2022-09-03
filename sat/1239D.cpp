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
const int maxik = 20;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
vector<vector<int>> g;
vector<vector<int>> g_adj;
vector<bool> vis;
vector<int> comp;
void dfs1(int v);
void dfs2(int v,int compi);
vector<int> show, show2;
void kosaraju();
stack<int> ss;
int n, m,t;
int counter;
void addEdge(int u, int v);
int main()
{
	es;
	cin >> t;
	while (t--)
	{
		counter = 0;
		g.clear();
		g_adj.clear();
		vis.clear();
		comp.clear();
		show.clear();
		show2.clear();
		cin >> n >> m;
		g.resize(n + 1);
		g_adj.resize(n + 1);
		vis.resize(n + 1,false);
		comp.resize(n + 1,-1);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			if (u != v)
			{
				addEdge(u, v);
			}
		}
		kosaraju();
	}
	return 0;
}
void addEdge(int u, int v)
{
	g[u].push_back(v);
	g_adj[v].push_back(u);
	return;
}
void dfs1(int v)
{
	vis[v] = true;
	for (int i = 0; i < g[v].size();i++)
	{
		if (!vis[g[v][i]])
		{
			dfs1(g[v][i]);
		}
	}
	ss.push(v);
	return;
}
void dfs2(int v,int compi)
{
	comp[v] = compi;
	if (compi==1)
	{
		show.push_back(v);
	}
	else
	{
		show2.push_back(v);
	}
	for (int i = 0; i < g_adj[v].size(); i++)
	{
		if (comp[g_adj[v][i]] == -1)
		{
			dfs2(g_adj[v][i], compi);
		}
	}
	return;
}
void kosaraju()
{
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs1(i);
		}
	}
	while (ss.size())
	{
		int u = ss.top();
		ss.pop();
		if (comp[u] == -1)
		{
			dfs2(u, ++counter);
		}
	}
	if (show2.size())
	{
		cout << "Yes\n";
		cout << show2.size() << " " << show.size()<<"\n";
		for (int i = 0; i < show2.size(); i++)
		{
			cout << show2[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < show.size(); i++)
		{
			cout << show[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "No\n";
	}
	return;
}
