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
const int maxik = 8e3 + 7;
const int maxN = 1e2;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

struct edge
{
	int a, b;
	int cap, cost;
	edge(int aa = 0, int bb = 0, int ca = 0, int co = 0)
	{
		a = aa;
		b = bb;
		cap = ca;
		cost = co;
	}
};

vector<edge> e;
vector<vector<int>> g;
void addEdge(int aa, int bb, int co);
int n, m, S, T;
int matrix[maxN][maxN];
ll edmonds();
bool BFS();
int bck[maxik], cost[maxik];
bool used[maxik];
int main()
{
	es;
	cin >> n >> m;
	T = (n*m) + 1;
	//T = S + 1;
	S = 0;
	g.resize(T + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> matrix[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if ((i + j) & 1)
			{
				addEdge(S, (i - 1)*m + j, 0);
				if (i >= 2)
				{
					addEdge((i - 1)*m + j, (i - 2)*m + j, matrix[i][j] != matrix[i - 1][j]);
				}
				if (j >= 2)
				{
					addEdge((i - 1)*m + j, (i - 1)*m + j - 1, matrix[i][j] != matrix[i][j - 1]);
				}
				if (i < n)
				{
					addEdge((i - 1)*m + j, (i)*m + j, matrix[i][j] != matrix[i + 1][j]);
				}
				if (j < m)
				{
					addEdge((i - 1)*m + j, (i - 1)*m + j + 1, matrix[i][j] != matrix[i][j + 1]);
				}
			}
			else
			{
				addEdge((i - 1)*m + j, T, 0);
			}
		}
	}
	cout << edmonds() << "\n";

	return 0;
}
void addEdge(int aa, int bb, int co)
{
	g[aa].push_back(e.size());
	edge e1(aa, bb, 1, co);
	e.push_back(e1);
	g[bb].push_back(e.size());
	edge e2(bb, aa, 0, -co);
	e.push_back(e2);
	return;
}
ll edmonds()
{
	ll pushed = 0;
	int flow;
	while (BFS())
	{
		flow = 1;
		int v = T;
		/*while (v != S)
		{
			flow = min(flow, e[bck[v]].cap);
			v = e[bck[v]].a;
		}
		v = T;*/
		while (v != S)
		{
			e[bck[v]].cap -= flow;
			e[bck[v] ^ 1].cap += flow;
			pushed += e[bck[v]].cost*flow;
			v = e[bck[v]].a;
		}
	}
	return pushed;
}
bool BFS()
{
	memset(bck, -1, sizeof bck);
	memset(cost, INF, sizeof cost);
	memset(used, 0, sizeof used);
	bck[S] = 0;
	cost[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty())
	{
		int v = q.front();
		//used[v] = false;
		q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int id = g[v][i];
			int to = e[id].b;
			if ((cost[to] > cost[v] + e[id].cost) && e[id].cap)
			{
				cost[to] = cost[v] + e[id].cost;
				bck[to] = id;
				//if (!used[to])
				//{
					q.push(to);
					//used[to] = true;
				//}
			}
		}
	}
	return bck[T] != -1;
}
