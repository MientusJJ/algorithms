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
const int maxik = 1e5 + 7;
const int maxN = 1e1;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

int n, m,u,v;
int ans[maxik], deg[maxik]; bool vis[maxik];
priority_queue<int> q;
vector<vector<int>> g;
int cnt;
int main()
{
	es;
	cin >> n >> m;
	cnt = n;
	g.resize(n + 1);
	while (m--)
	{
		cin >> u >> v;
		g[v].push_back(u);
		deg[u]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!deg[i])
		{
			q.push(i);
			vis[u];
		}
	}
	while (q.size())
	{
		auto t = q.top();
		q.pop();
		ans[t] = cnt--;
		for (int i = 0; i < g[t].size(); i++)
		{
			auto u = g[t][i];
			deg[u]--;
			if (!deg[u] && !vis[u])
			{
				q.push(u);
				vis[u] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
