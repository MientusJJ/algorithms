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
const int maxik = 2e5 + 11;
const int maxN = 22;
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
ll dp[2007][maxN];
ll sil[maxik], rev[maxik];
ll powik(ll a, ll b = modik - 2);
vector<pii> pts; ll count(ll a, ll b);
int n, m, k, sum;
int main()
{
	es;
	sil[0] = 1;
	for (int i = 1; i < maxik; i++)
	{
		sil[i] = sil[i - 1] * i;
		sil[i] %= modik;
	}
	//rev[4000] = powik(4000);
	for (int i = 0; i < maxik; i++)
	{
		/*	rev[i - 1] = i * rev[i];
			rev[i - 1] %= modik;*/
		rev[i] = powik(sil[i]);
	}
	dp[0][0] = 1;
	cin >> n >> m >> k >> sum;
	pts.reserve(k + 2);
	pts.emplace_back(1, 1);
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		pts.emplace_back(x, y);
	}
	pts.emplace_back(n, m);
	sort(begin(pts) + 1, end(pts) - 1, [](const pii& fi, const pii& se)
		{
			if (fi.first == se.first)
			{
				return fi.second < se.second;
			}
	return fi.first < se.first;
		});
	++k;
	for (int i = 1; i <= k; i++)
	{

		for (int j = 0; j < i; j++)
		{
			if (pts[j].second > pts[i].second)
			{
				continue;
			}
			ll temp = count(pts[i].first - pts[j].first, pts[i].second - pts[j].second);
			for (int kk = 1; kk < maxN; kk++)
			{
				dp[i][kk] += dp[j][kk - 1] * temp;
				dp[i][kk] %= modik;
			}
		}
		for (int kk = 1; kk < maxN - 1; kk++)
		{
			dp[i][kk] -= dp[i][kk + 1];
			dp[i][kk] %= modik;
		}
	}
	ll noBlack = count(n - 1, m - 1);
	ll ans = 0;
	for (int i = 1; i < maxN; i++)
	{
		ans += sum * dp[k][i];
		ans %= modik;
		noBlack -= dp[k][i];
		noBlack += modik;
		noBlack %= modik;
		sum = (sum + 1) / 2;

	}
	ans += noBlack;
	ans += modik;
	ans %= modik;
	cout << (ans * powik(count(n - 1, m - 1))) % modik;
	return 0;
}
ll powik(ll a, ll b)
{
	if (b == 0)
	{
		return 1ll;
	}
	else
	{
		if (b & 1)
		{
			return (powik(a, b - 1) % modik * a) % modik;
		}
		else
		{
			ll res = powik(a, b / 2) % modik;
			return (res * res) % modik;
		}
	}
}
ll count(ll a, ll b)
{
	return ((sil[a + b] * (rev[a])) % modik * rev[b]) % modik;
}
