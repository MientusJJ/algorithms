#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
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
const int maxik = 2e5 + 7;
const int maxValue = 30;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;


vector <vector<int> > g;
ll ss[maxik];
ll dp[maxik];
int n;
void dfs(int v, int par);
void centroid(int v, int par);
int ans;
int main()
{
	es;
	ans = 1;
	cin >> n;
	g.rs(n + 1);
	for (int i = 1; i <= n; i++)
	{
		ss[i] = 1;
		dp[0];
	}
	ss[0] = INF;
	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	centroid(1, 0);
	cout << dp[ans];
	return 0;
}
void dfs(int v, int par)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		if (g[v][i] != par)
		{
			dfs(g[v][i], v);
			ss[v] += ss[g[v][i]];
			dp[v] += dp[g[v][i]];
		}
		
	}
	dp[v] += ss[v];
	return;
}
void centroid(int v, int par)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		if (g[v][i] != par)
		{
			dp[g[v][i]] = dp[v] + n - 2 * ss[g[v][i]];
			if (dp[g[v][i]] > dp[ans])
			{
				ans = g[v][i];
			}
			centroid(g[v][i], v);
		}
	}
	return;
}
