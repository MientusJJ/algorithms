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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 1e6 + 7;
const int maxN = 1 << 22;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;

int n;
vector<int> dp,tab;
int main()
{
	es;
	//txt;
	cin >> n;
	tab.resize(n + 1);
	dp.resize(maxN + 7, INF);
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
		dp[tab[i]] = i;
	}
	for (int i=0; i <22; i++)
	{
		for (int j = 0; j < maxN; j++)
		{
			if (j & (1 << i))
			{
				dp[j] = min(dp[j], dp[j ^ (1 << i)]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int indx = -1 + maxN - tab[i];
		if (dp[indx] < INF)
		{
			cout << tab[dp[indx]] << " ";
			continue;

		}
		cout << "-1 ";
	}
	return 0;
}
