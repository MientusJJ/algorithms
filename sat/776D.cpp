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
const int maxik = 5e5+7;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
vector<vector<int>> g;
//vector<vector<int>> g_prev;
vector<vector<int>> doors;
vector<bool> opened;
int n, m;
bool vis[maxik];
int comp[maxik];
void dfs1(int v);
void dfs2(int v,int c);
stack<int> st;
void makeEdges(int v, int u, bool p);
bool Kosaraju();
int main()
{
	es;
	cin >> n >> m;
	opened.resize(maxik);
	doors.resize(maxik);
	g.resize(maxik);
	//g_prev.resize((n + 1) * 2);
	for (int i = 1; i <= n; i++)
	{
		bool b;
		cin >> b;
		opened[i]=b;
	}
	for (int i = 0; i < m; i++)
	{
		int j,key;
		cin >> j;
		for (int k = 0; k < j; k++)
		{
			cin >> key;
			doors[key].push_back(i + 1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		makeEdges(doors[i][0], doors[i][1], opened[i]);
	}
	if (Kosaraju())
	{
		Y;
	}
	else
	{
		N;
	}
	return 0;
}
void makeEdges(int v, int u, bool p)
{
	int vv = 2 * v;
	int uu = 2 * u;
	if (p)
	{
		g[vv].push_back(uu);
		g[uu].push_back(vv);
		g[uu ^ 1].push_back(vv ^ 1);
		g[vv ^ 1].push_back(uu ^ 1);
	}
	else
	{
		g[vv].push_back(uu^1);
		g[uu^1].push_back(vv);
		g[vv^1 ].push_back(uu );
		g[uu].push_back(vv^1 );
	}
	return;
}
bool Kosaraju()
{
	for (int i = 2; i <= m*2+1; i++)
	{
		if (!vis[i])
		{
			dfs1(i);
		}
	}
	int p = 0;
	memset(comp, -1, sizeof comp);
	while (st.size())
	{
		int v = st.top();
		st.pop();
		if (comp[v]==-1)
		{
			dfs2(v,++p);
		}
	}
	for (int i = 2; i <= 2*m+1; i+=2)
	{
		if (comp[i] == comp[i + 1])
		{
			return false;
		}
	}
	return true;
}
void dfs1(int v)
{
	vis[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		if (!vis[g[v][i]])
		{
			dfs1(g[v][i]);
		}
	}
	st.push(v);
	return;
}
void dfs2(int v, int c)
{
	comp[v] = c;
	for (int i = 0; i < g[v].size(); i++)
	{
		if (comp[g[v][i]] == -1)
		{
			dfs2(g[v][i], c);
		}
	}
	return;
}
