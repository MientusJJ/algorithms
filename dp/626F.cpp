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
#define mst(v,k) memset((v),(m),sizeof(v)); 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 2e2+7;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;

int n,m;
vector<int> tab;
int res = 0;
ll dp[tight][maxik][maxik * 5];
int main()
{
	es;//txt;
	cin >> n >> m;
	dp[0][0][0] = 1;
	int cur = 0;
	tab.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
	}
	sort(all(tab));
	tab[0] = tab[1];
	for (int i = 1; i <= n; i++)
	{
		cur ^= 1;
		for (int p = 0; p < maxik; p++)
		{
			for (int u = 0; u < maxik * 5; u++)
			{
				dp[cur][p][u] = 0;
			}

		}
		//mst(dp[cur], 0);
		int t = tab[i] - tab[i - 1];
		for (int j = 0; j < i; j++)
		{
			int r = j * t;
			for (int k = 0; k <= m; k++)
			{
				if (!dp[cur ^ 1][j][k])
				{
					continue;
				}
				if (r + k > m)
				{
					continue;
				}
				int temp = r + k;
				dp[cur][j + 1][temp] += dp[cur ^ 1][j][k];
				dp[cur][j + 1][temp] %= modik;
				dp[cur][j][temp] += dp[cur ^ 1][j][k];
				dp[cur][j][temp] %= modik;
				if (j)
				{
					dp[cur][j - 1][temp] += dp[cur^1][j][k]*j;
					dp[cur][j - 1][temp] %= modik;
				}
				if (j)
				{
					dp[cur][j][temp] += dp[cur ^ 1][j][k] * j;
					dp[cur][j][temp] %= modik;
				}
			}
		}
	}
	for (int i = 0; i <= m; i++)
	{
		res += dp[cur][0][i];
		res %= modik;
	}
	cout << res%modik << endl;
	return 0;
}
