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
const int maxN = 1 << 18;
const int INF = 0x3f3f3f3f;
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
ll counterek[maxik];
ll ans = 0;
ll powik(ll number, ll power, ll modek)
{
	if (!power)
	{
		return 1ll;
	}
	if (power % 2)
	{
		return (number*(powik(number, power - 1, modek) % modek)) % modek;
	}
	else
	{
		ll ret = (powik(number, power / 2, modek) % modek);
		return (ret*ret) % modek;
	}
}
int main()
{
	es;
	//txt;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
		counterek[tab[i]]++;
	}
	for (int k = 0; k < 20; k++)
	{
		for (int i = 0; i<maxik; i++)
		{
			if (i & (1 << k))
			{
				counterek[i^(1<<k)]+=counterek[i];
			}
		}
	}
	bitset<40> word;
	for (int i = 0; i < maxik; i++)
	{
		word.set();
		word &= i;
		if (word.count() & 1)
		{
			ans = ((ans - ((powik(2, counterek[i], modik) - 1 + modik) % modik)) + modik) % modik;
		}
		else
		{
			ans = ((ans + ((powik(2, counterek[i], modik) - 1 + modik) % modik)) + modik) % modik;
		}
	}
	cout << ans << endl;
	return 0;

}
