#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <string>
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 2e6 + 7;
const int maxN = 2010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

char ranking[maxik];
int n;
int centroid = 1;
vector<vector<int> > g;
int sizes[maxik];
void dfs(int v, int par);
int thrown[maxik];
char Commando = 'A';
int findcentroid(int v,int high, char command);
queue<int> q;
int main()
{
	es;
	cin >> n;
	g.rs(n + 1);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	centroid = findcentroid(1, sizes[1], Commando);
	for (int i = 0; i < g[centroid].size(); i++)
	{
		if (!thrown[g[centroid][i]])
		{
			q.push(g[centroid][i]);
		}
	}
	q.push(0);
	Commando++;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (v == 0)
		{
			Commando++;
			if (q.size())
			{
				q.push(0);
			}
			continue;
		}
		centroid = findcentroid(v, sizes[v], Commando);
		for (int i = 0; i < g[centroid].size(); i++)
		{
			if (!thrown[g[centroid][i]])
			{
				q.push(g[centroid][i]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ranking[i] << " ";
	}
	return 0;
}
void dfs(int v, int par)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if (u != par)
		{
			dfs(u, v);
			sizes[v] += sizes[u];
		}
	}
	sizes[v]++;
	return;
}
int findcentroid(int v, int high, char command)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		if (!thrown[g[v][i]] && sizes[g[v][i]] > (high / 2))
		{
			sizes[v] -= sizes[g[v][i]];
			sizes[g[v][i]] = high;
			return  findcentroid(g[v][i],high,command);
		}
	}
	thrown[v] = true;
	ranking[v] = command;
	return v;
}
