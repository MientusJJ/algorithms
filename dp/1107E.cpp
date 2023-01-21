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
const int maxik = 1e2 + 3;
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


ll dp[maxik][maxik][maxik];

int a[maxik];
int val[maxik];
int n;
int main()
{
	es;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for(int i=1;i<=n;i++)
	{
		cin >> val[i];
	}
	for(int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			dp[i][i][j] = val[j];
		}
	}
	for(int len=1;len<n;len++)
	{
		for(int l=1;l+len<=n;l++)
		{
			int r = l + len;
			for(int k=1;k<=n;k++)
			{
				dp[l][r][k] = val[k] + dp[l + 1][r][1];
				for(int rr=l+1;rr<=r;rr++)
				{
					if (a[l] == a[rr])
					{
						dp[l][r][k] = max(dp[l][r][k], dp[l + 1][rr - 1][1] + dp[rr][r][k + 1]);
					}
				}
			}
		}
	}
	cout << dp[1][n][1];
	return 0;
}
