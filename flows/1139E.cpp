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
const int maxik = 4e4 + 7;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

struct edge
{
	int a;
	int b;
	int flow;
	int cap;
	edge(int aa, int bb, int v,int c)
	{
		a = aa;
		b = bb;
		flow = v;
		cap = c;
	}
	edge()
	{
		a = b = flow = cap = 0;
	}
};

vector<int> g[maxik];
vector<int> mexes[maxik];
vector<edge> e;
pii students[maxik];
int n, m,days[maxik],d;
int ptr[maxik],dis[maxik];
int S, T;
set<int> ss;
bool BFS();
int dinic();
int mex = 0;
int res[maxik];
int dfs(int v,int flow=INF);
void addEdge(int a, int b, int c)
{
	edge e1(a, b, 0, c);
	edge e2(b, a, 0, 0);
	g[a].push_back(e.size());
	e.push_back(e1);
	g[b].push_back(e.size());
	e.push_back(e2);
}
int main()
{
	es;
	cin >> n >> m;
	S = 0;
	T = 2* m + 3;
	for (int i = 1; i <= n; i++)
	{
		cin >> students[i].first;
		ss.insert(i);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> students[i].second;

	}
	cin >> d;
	for (int i = 1; i <= d; i++)
	{
		cin >> days[i];
		ss.erase(days[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		addEdge(S, i, 1);
	}
	for (int i = 0; i <= m+1; i++)
	{
		addEdge(i + m + 1, T, 1);
	}
	for (int v : ss)
	{
		mexes[students[v].first].push_back(students[v].second);
	}
	while (1)
	{
		while (mexes[mex].size())
		{
			addEdge(mexes[mex].back(), m + mex + 1, INF);
			mexes[mex].pop_back();
		}
		if (dinic()) mex++;
		else break;

	}
	res[d] = mex;
	for (int i = d; i; i--)
	{
		mexes[students[days[i]].first].push_back(students[days[i]].second);
		if (students[days[i]].first <= mex)
		{
			while (mexes[students[days[i]].first].size())
			{
				addEdge(mexes[students[days[i]].first].back(), m + students[days[i]].first + 1, INF);
				mexes[students[days[i]].first].pop_back();
			}
		}
		while (1)
		{
			while (mexes[mex].size())
			{
				addEdge(mexes[mex].back(), m + mex + 1, INF);
				mexes[mex].pop_back();
			}
			if (dinic()) mex++;
			else break;

		}
		res[i - 1] = mex;
	}
	for (int i = 1; i <= d; i++)
	{
		cout << res[i] << endl;
	}
	return 0;

}
int dinic()
{
	int ans = 0;
	while (BFS())
	{
		memset(ptr, 0, sizeof ptr);
		while (int f = dfs(S))
		{
			ans += f;
		}
	}
	return ans;
}
bool BFS()
{
	queue<int> q;
	memset(dis, -1, sizeof dis);
	dis[S] = 0;
	q.push(S);
	while (q.size() && dis[T]==-1)
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int ed = g[v][i];
			auto &t = e[ed];
			if (dis[t.b] == -1 && t.flow < t.cap)
			{
				dis[t.b] = dis[v] + 1;
				q.push(t.b);
			}
			
		}
	}
	return dis[T] != -1;
}
int dfs(int v, int flow)
{
	if (!flow)
	{
		return 0;
	}
	if (v == T)
	{
		return flow;
	}
	for (; ptr[v] < g[v].size(); ptr[v]++)
	{
		int ed = g[v][ptr[v]];
		auto &t = e[ed];
		if(dis[v]+1!=dis[t.b])
		{
			continue;
		}
		int pushed=dfs(t.b, min(flow, t.cap - t.flow));
		if (pushed)
		{
			e[ed].flow += pushed;
			e[ed ^ 1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
