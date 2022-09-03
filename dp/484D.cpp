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
const int maxik = 1e6 + 7;
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

int n;
ll dp[maxik];
ll tab[maxik];
bool check(int indx);
int main()
{
	es;//txt;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
	}
	if (n == 1)
	{
		cout << "0" << endl;
		return 0;
	}
	if (n == 2)
	{
		cout << abs(tab[2] - tab[1]) << endl;
	}
	else
	{
		dp[2] = abs(tab[2] - tab[1]);
		for (int i = 3; i <= n; i++)
		{
			if (check(i))
			{
				dp[i] = dp[i - 1] + abs(tab[i] - tab[i - 1]);
				continue;
			}
			dp[i] = max(dp[i - 1], dp[i - 2] + abs(tab[i] - tab[i - 1]));
		}
		cout << dp[n] << endl;
	}
	return 0;
}
bool check(int indx)
{
	return (((tab[indx - 2] < tab[indx - 1]) && (tab[indx - 1] < tab[indx])) || ((tab[indx - 2] > tab[indx - 1]) && (tab[indx - 1] > tab[indx])));
}
