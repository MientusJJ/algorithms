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
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
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
const int maxik = 1e5 + 7;
const int maxN = 20*2+7;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;

int in[maxik];
int ans[maxik];
int dp[maxik][maxN],temp[maxik][maxN];
vector<vector<int>> g;
void dfs(int v,int parent);
void dfs2(int v, int parent);
int n, k,range;
const int root = 5;
ll result=0;
int main()
{
	es;
	cin >> n >> k;
	range = 2 * k - 1;
	g.resize(n + 1);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);

	}
	for (int i = 1; i <= n; i++)
	{
		cin >> in[i];
	}
	dfs(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
	{
		cout << (ans[i] > 0) << " ";
	}
	return 0;
}
void dfs(int v,int par)
{
	dp[v][0] = in[v];
	for (int u : g[v])
	{
		if (u != par)
		{
			dfs(u, v);
			for (int i = 0; i <= range; i++)
			{
				dp[v][(i+1)%(range+1)] ^= dp[u][i];
			}
		}
	}
	return;
}
void dfs2(int v, int parent)
{
	for (int i = k; i <= range; i++)
	{
		ans[v] ^= dp[v][i];
	}
	for (int u : g[v])
	{
		if (u != parent)
		{
			for (int i = 0; i <= range; i++)
			{
				dp[v][(i + 1) % (range + 1)] ^= dp[u][i];
			}
			for (int i = 0; i <= range; i++)
			{
				dp[u][(i + 1) % (range + 1)] ^= dp[v][i];
			}
			dfs2(u, v);
			for (int i = 0; i <= range; i++)
			{
				dp[u][(i + 1) % (range + 1)] ^= dp[v][i];
			}
			for (int i = 0; i <= range; i++)
			{
				dp[v][(i + 1) % (range + 1)] ^= dp[u][i];
			}
			
		}
		
	}
	return;
}
