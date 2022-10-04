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
const int maxik = 5e5 + 7;
const int maxN = 60;
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

struct shrub
{
	ll red, blue;
	shrub()
	{
		red = blue = 0ll;
	}
	shrub(ll r, ll b) : red(r),blue(b){}
};

int n, k;
ll r, b;
vector<shrub> a;
vector<vector<bool>> dp;
int main()
{
	es;
	cin >> n >> k;
	a.resize(n + 1);
	dp.resize(n + 1, vector<bool>(k, 0));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].red >> a[i].blue;
		b+= a[i].blue;
		r+=a[i].red;
	}
	if ((b + r) / k == (b / k + r / k))
	{
		cout << (b + r) / k;
		return 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (!dp[i - 1][j]) continue;
			dp[i][j] = 1;
			for (int l = 1; l < k; l++)
			{
				if (l <= a[i].red && k-l <= a[i].blue)
				{
					dp[i][(l + j) % k] = 1;
				}
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (dp[n][i])
		{
			if ((b + r) / k == ((b + i) / k) + ((r - i) / k))
			{
				cout << (b + r) / k;
				return 0;
			}
		}
	}
	cout << max(0ll, (r + b) / k - 1);
	return 0;
}
