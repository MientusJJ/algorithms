#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//#define DEBUG


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
#include <fstream>
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
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
const int maxik = 7e1+2;
const int maxN = 30;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;
const double PI = acos(-1.);
#ifdef DEBUG
fstream in("C:/Temp/input.txt", ios::in);
fstream out("C:/Temp/output.txt", ios::out | ios::trunc);
#define cin in
#define cout out
#endif // DEBUG 

int n, m, k;
int a[maxik][maxik];
int dp[maxik][maxik][maxik][maxik];
int main()
{
	es;
	for (int i = 0; i < maxik; i++)
	{
		for (int j = 0; j < maxik; j++)
		{
			for (int p = 0; p < maxik; p++)
			{
				for (int kk = 0; kk < maxik; kk++)
				{
					dp[i][j][p][kk] = -INF;
				}
			}
		}
	}
	cin >> n >> m >> k;
	dp[0][m][0][0] = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int p=0;p<=m/2;p++)
			{
				for(int kk=0;kk<k;kk++)
				{
					if(j==1)
					{
						dp[i][j][0][kk] = max(dp[i][j][0][kk], dp[i - 1][m][p][kk]);
						dp[i][j][1][kk] = max(dp[i][j][1][kk], dp[i - 1][m][p][((kk - a[i][j] + k) % k + k) % k] + a[i][j]);
					}
					else
					{
						dp[i][j][p][kk] = max(dp[i][j][p][kk], dp[i][j-1][p][kk]);
						if(p>=1)
						{
							dp[i][j][p][kk] = max(dp[i][j][p][kk], dp[i][j-1][p-1][((kk - a[i][j] + k) % k + k) % k] + a[i][j]);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=m/2;i++)
	{
		ans = max(ans, dp[n][m][i][0]);
	}
	cout << ans;
	return 0;
}
