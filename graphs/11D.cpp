#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <fstream>
#include <chrono>
#include <random>
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
//#define TXTcreate freopen("C:/Temp/output.txt","w",stdout);freopen("input.txt","w",stdout);
#define txt  freopen("C:/Temp/input.txt","r",stdin); freopen("C:/Temp/output.txt","w",stdout);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define randomizer mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define mst(v,k) memset((v),(k),sizeof(v)); 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 5e1;
const int maxN = 1 << 20;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;

bool g[maxik][maxik];
int n, m;
ll ans = 0;
ll dp[maxN][20];

int main()
{
	es;
	//txt;
	cin >> n >> m;
	ans = -m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u-1][v-1] = 1;
		g[v-1][u-1] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		dp[1 << i][i] = 1;
	}
	for (int i = 1; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!dp[i][j])
			{
				continue;
			}
			for (int k = 0; k < n; k++)
			{
				if (((1 << k) < (i&-i)))
				{
					continue;
				}
				if (!g[j][k])
				{
					continue;
				}
				if ((1 << k) & i)
				{
					if ((1 << k) &(i &-i))
					{
						ans += dp[i][j];
					}
				}
				else
				{
					dp[i | 1 << k][k] += dp[i][j];
				}
			}
		}
	}
	cout << ans/2;
	return 0;
}
