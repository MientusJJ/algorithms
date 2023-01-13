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
const int maxik = 3e4 + 7;
const int maxN = 250;
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

int n, d;
int gems[maxik];
int dp[maxik][maxN * 2 + 7];
int main()
{
	es;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		gems[val]++;
	}
	mst(dp, -1);
	int ans = dp[d][min(d, 250)] = gems[d];
	for (int i = d; i < maxik; i++)
	{
		for (int j = 1; j < maxN * 2 + 6; j++)
		{
			if (dp[i][j] == -1)
			{
				continue;
			}
			int l = max(j, d - maxN + j);
			if (i + l - 1 < maxik && l != 1 && j != 1)
			{
				dp[i + l - 1][j - 1] = max(dp[i + l - 1][j - 1], dp[i][j] + gems[i + l - 1]);
				ans = max(ans, dp[i + l - 1][j - 1]);
			}
			if (i + l < maxik)
			{
				dp[i + l][j] = max(dp[i + l][j], dp[i][j] + gems[i + l]);
				ans = max(ans, dp[i + l][j]);
			}
			if (i + l + 1 < maxik)
			{
				dp[i + l + 1][j + 1] = max(dp[i + l + 1][j + 1], dp[i][j] + gems[i + l + 1]);
				ans = max(ans, dp[i + l + 1][j + 1]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
