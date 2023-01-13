#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define DEBUG


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
const int maxik = 19;
const int maxN = 1<<maxik;
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

int n;
vector<vector<double>> chances;
vector < vector<double>> dp;// dp[maxN][maxik];
int main()
{
	es;
	cin >> n;
	chances.resize(n, vector<double>(n));
	dp.resize(1 << n, vector<double>(n));
	for (int i{ 0 };i<n;i++)
	{
		for(int j{0};j<n;j++)
		{
			cin >> chances[i][j];
			if(j==0)
			{
				chances[i][j] = 0.;
			}
		}
	}
	dp[1][0] = 1.;
	for(int mask=0;mask<(1<<n);mask++)
	{
		for(int i=0;i<n;i++)
		{
			if(mask&(1<<i))
			{
				for(int j=0;j<n;j++)
				{
					if(i!=j && (mask&(1<<j)))
					{
						dp[mask][i] = max(dp[mask][i], chances[i][j] * dp[mask ^ (1 << j)][i] + chances[j][i] * dp[mask ^ (1 << i)][j]);
					}
				}
			}
		}
	}
	double ans = -1.;
	//ans = dp[(1 << n) - 1][0];
	for(int i=0;i<n;i++)
	{
		ans = max(ans, dp[(1<<n) - 1][i]);
	}
	prec(6) << ans;

	return 0;
}
