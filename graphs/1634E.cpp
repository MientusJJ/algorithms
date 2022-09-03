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

int n, m,id;
vector<vector<int>> v;
vector<vector<char> > ans;
vector <vector<bool>> vis;
map<int, int> nums, ids;
vector < vector<tuple<int, int, int> > > g;
bool xd = 0;
void dfs(int);
int main()
{
	es;
	cin >> m;
	id = m;
	v.resize(m + 1);
	ans.resize(m + 1);
	vis.resize(m + 1);
	for (int i = 1; i <= m; i++)
	{
		cin >> n;
		v[i].resize(n + 1);
		vis[i].resize(n + 1,false);
		ans[i].resize(n + 1, 0);
		for (int j = 1; j <= n; j++)
		{
			cin >> v[i][j];
			nums[v[i][j]]++;
			if (!ids[v[i][j]])
			{
				ids[v[i][j]] = ++id;
				g.resize(id + 1);
			}
			g[ids[v[i][j]]].push_back({ i,i,j });
			g[i].push_back({ ids[v[i][j]],i,j });
		}
	}
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		if (it->second % 2)
		{
			N;
			return 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		dfs(i);
	}
	Y;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < ans[i].size(); j++)
		{
			cout << ans[i][j];
		}
		cout << "\n";
	}
	return 0;
}
void dfs(int v)
{
	while(g[v].size())
	{
		auto [u, x, y] = g[v].back();
		g[v].pop_back();
		if (!vis[x][y])
		{
			vis[x][y] = true;
			dfs(u);
			xd = !xd;
			if (xd)
			{
				ans[x][y] = 'L';
			}
			else
			{
				ans[x][y] = 'R';
			}
		}
	}
	return;
}
