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
#define es ios::sync_with_stdio(false);cin.tie(0);
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 1e5 +100;
const int maxN = 18;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

vector<vector<int> > g;
int lca[maxik][maxN];
int n,m;
int sig, v;
int red[maxik];
int depth[maxik];
vector<int> redders;
void dfs(int v, int par);
void swap(int &v, int &u);
int equal(int v, int u);
void bfs();
int main()
{
	es;
	cin >> n >> m;
	g.resize(n + 1);
	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	lca[1][0] = 1;
	dfs(1, 0);
	for (int i = 1; i < maxN; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			lca[j][i] = lca[lca[j][i - 1]][i - 1];
		}
	}
	int maxensius =100;
	for (int i = 1; i <= n; i++)
	{
		red[i] = depth[i];
	}

;	for (int i = 0; i < m; i++)
	{
		cin >> sig >> v;
		if (sig & 1)
		{
			redders.push_back(v);
			if (redders.size() == maxensius)
			{
				bfs();
			}
		}
		else
		{
			int result = red[v];
			for (int i = 0; i < redders.size(); i++)
			{
				result = min(result, depth[redders[i]] + depth[v] - 2 * equal(v, redders[i]));
			}
			cout << result << "\n";
		}
	}
	return 0;
}
void dfs(int v, int par)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		if (g[v][i] != par)
		{
			lca[g[v][i]][0] = v;
			depth[g[v][i]] = depth[v] + 1;
			dfs(g[v][i], v);
		}
	}
	return;
}
void swap(int &v, int &u)
{
	int temp = v;
	v = u;
	u = temp;
	return;
}
int equal(int v, int u)
{
	if (depth[v] > depth[u])
	{
		swap(u, v);
	}
	for (int i = maxN - 1; i >= 0; i--)
	{
		if (depth[lca[u][i]] >= depth[v])
		{
			u = lca[u][i];
		}
	}
	if (u == v)
	{
		return depth[v];
	}
	for (int i = maxN - 1; i >= 0; i--)
	{
		if (lca[u][i]!=lca[v][i])
		{
			u = lca[u][i];
			v = lca[v][i];
		}
	}
	return depth[lca[v][0]];
}
void bfs()
{
	queue <int> q;
	for (int i = 0; i < redders.size(); i++)
	{
		q.push(redders[i]);
		red[redders[i]] = 0;
	}
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0;i< g[v].size(); i++)
		{
			if (red[v] + 1 < red[g[v][i]])
			{
				red[g[v][i]] = red[v] + 1;
				q.push(g[v][i]);
			}
		}
	}
	redders.clear();
	return;
}
