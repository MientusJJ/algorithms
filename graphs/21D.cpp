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
const int maxik = 20;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
ll sum = 0;
int n, m;
int tab[maxik][maxik];
int degree[maxik];
vector<int> v;
int main()
{
	es;
	cin >> n >> m;
	memset(tab, INF, sizeof tab);
	for (int i = 1; i <= n; i++)
	{
		tab[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v,w;
		cin >> u >> v >> w;
		degree[u]++;
		degree[v]++;
		sum += w;
		tab[u][v] = min(tab[u][v], w);
		tab[v][u] = min(tab[v][u], w);
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <=n; j++)
			{
				tab[i][j] = min(tab[i][j], tab[i][k] + tab[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ((tab[i][j] == INF && degree[i] && degree[j]) || (!degree[1]&& m))
			{
				cout << "-1\n";
				return 0;
			}
		}
	}
	for (int i = 1; i <=n ; i++)
	{
		if (degree[i] % 2)
		{
			v.push_back(i);
		}
	}
	vector<int> dis(1 << v.size(), INF);
	dis[0] = 0;
	for (int i = 0; i < dis.size(); i++)
	{
		for (int j = 0; j <v.size(); j++)
		{
			if (!((1 << j) & i))
			{
				for (int k = j + 1; k < v.size(); k++)
				{
					if (!((1 << k) & i))
					{
						int xx = i | (1 << k) | (1 << j);
						dis[xx ] = min(dis[xx], dis[i] + tab[v[j]][v[k]]);
					}
				}
			}
		}
	}
	cout << sum + dis[dis.size() - 1] << "\n";
	return 0;
}
