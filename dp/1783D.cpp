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
const int maxik = 3e2 + 7;
const int maxN = 2e5+7;
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

vector<int> a;
vector<vector<int>> dp;
const int rangeN = 2e5;
const int zero = rangeN/2;

int n;
int main()
{
	es;
	cin >> n;
	a.resize(n + 1);
	dp.resize(n + 1, vector<int>(rangeN+7));
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	dp[2][zero + a[2]] = 1;
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j< rangeN;j++)
		{
			if(!dp[i - 1][j])
			{
				continue;
			}
			int val = j - zero;
			dp[i][a[i]-val+zero] += dp[i - 1][j];
			dp[i][a[i] - val + zero] %= modik2;
			if(val)
			{
				dp[i][a[i] + val + zero] += dp[i - 1][j];
				dp[i][a[i] + val + zero] %= modik2;
			}
		}
	}
	int ans{ 0 };
	for(int i=0;i< rangeN;i++)
	{
		ans += dp[n][i];
		ans %= modik2;
	}
	cout << ans;
	return 0;
}
