#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define maxik 1010
#define INF 0x4f4f4f4f
#define es ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll = long long;
struct edge {
	int a,b;
	int flow, cap;
};
vector<edge> e;
vector<int> conn[maxik];
int dis[maxik];
int ptr[maxik];
int matrix[maxik][maxik];
void addEdge(int aa, int bb, int c);
int dinic(int s, int t);
bool bfs(int s, int t);
int dfs(int v, int flow, int t,int s);
int n,m;
int s, t;
int now[maxik], desired[maxik];
int expe,expe2;
int main()
{
	es;
	expe=s = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> now[i];
		expe2 += now[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> desired[i];
		expe += desired[i];
	}
	t = 2 * n + 1;
	for (int i = 1; i <= n; i++)
	{
		addEdge(s, i, now[i]);
		addEdge(n + i, t, desired[i]);
		addEdge(i, i + n, now[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		addEdge(a, b + n, now[a]);
		addEdge(b, a + n, now[b]);
	}
	int res=dinic(s, t);
	if (res == expe && res== expe2)
	{
		cout << "YES\n";
		for (int a = 1; a <= n; a++)
		{
			for (int i = 0; i < conn[a].size(); i++)
			{
				int id = conn[a][i];
				if (e[id].b > n)
				{
					matrix[a][e[id].b-n] += e[id].flow;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
void addEdge(int aa, int bb, int c)
{
	edge e1 = {aa, bb, 0, c};
	edge e2 = { bb,aa,0,0 };
	conn[aa].push_back(e.size());
	e.push_back(e1);
	conn[bb].push_back(e.size());
	e.push_back(e2);
	return;
}
int dinic(int s, int t)
{
	int maxFlow = 0;
	while (bfs(s, t))
	{
		memset(ptr, 0, sizeof ptr);
		while (int pushed = dfs(s, INF,t,s))
		{
			maxFlow += pushed;
		}
	}
	return maxFlow;
}
bool bfs(int s, int t)
{
	memset(dis, -1, sizeof dis);
	queue<int> q;
	dis[s] = 0;
	q.push(s);
	while (!(q.empty()) && dis[t] == -1)
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < conn[v].size(); i++)
		{
			int id = conn[v][i];
			int to = e[id].b;
			if (dis[to] == -1 && e[id].flow < e[id].cap)
			{
				q.push(to);
				dis[to] = dis[v] + 1;
			}
		}
	}
	return dis[t] != -1;
}
int dfs(int v, int flow,int t,int s)
{
	if (flow == 0)
	{
		return 0;
	}
	if (t == v)
	{
		return flow;
	}
	while (ptr[v]<conn[v].size())
	{
		int id = conn[v][ptr[v]];
		int to = e[id].b;
		ptr[v]++;
		if (dis[to] != dis[v] + 1)
		{
			continue;
		}
		int pushed = dfs(to, min(flow, (e[id].cap - e[id].flow)), t,s);
		if (pushed)
		{
			e[id].flow += pushed;
			e[id ^ 1].flow -= pushed;
			if (v != s && to != t)
			{
				int k = e[id].a;
				if (k > n)
				{
					k -= n;
				}
				int l = e[id].b;
				if (l > n)
				{
					l -= n;
				}
			}
			return pushed;
		}
	}
	return 0;
}
