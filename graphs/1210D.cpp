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

vector<vector<int>> g;
vector<int> deg;
void swapik(int &a, int &b);
int n, m;
ll Ans = 0;
ll coll(int v);
void solve(int v);
int main()
{
	es;
	cin >> n >> m;
	g.resize(n + 1);
	deg.resize(n + 1, 0);
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
		if (u < v)
		{
			swapik(u, v);
		}
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		Ans += coll(i);
	}
	cout << Ans << "\n";
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u;
		solve(u);
	}
	return 0;
}
void swapik(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
	return;
}
ll coll(int v)
{
	return (deg[v] - g[v].size())*g[v].size();
}
void solve(int v)
{
	Ans -= coll(v);
	while (g[v].size())
	{
		int a = g[v].back();
		Ans -= coll(a);
		g[a].push_back(v);
		Ans += coll(a);
		g[v].pop_back();
	}

	cout << Ans << "\n";
	return;
}
