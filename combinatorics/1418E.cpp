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
#define TXT  freopen("C:/Temp/input.txt","r",stdin); freopen("C:/Temp/output.txt","w",stdout);
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
const int maxik = 2e5 + 7;
const int maxN = 1 << 20;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;

ll damage[maxik];
ll n, m;
ll prefDamage[maxik];
ll powik(ll number, ll power = modik2 - 2);
int main()
{
	es;
	//TXT;
	cin >> n >> m;
	memset(damage, 0, sizeof damage);
	memset(prefDamage, 0, sizeof prefDamage);
	for (int i = 1; i <=n; i++)
	{
		cin >> damage[i];
	}
	sort(damage + 1, damage + n + 1);
	for (int i = 1; i <= n; i++)
	{
		prefDamage[i] = prefDamage[i - 1] + damage[i];
		prefDamage[i] %= modik2;
	}
	while (m--)
	{
		ll shield,durability;
		cin >> durability >> shield;
		ll indx = lower_bound(damage + 1, damage + n + 1, shield) - damage;
		ll attacks = n + 1 - indx;
		if (indx > n || attacks<durability)
		{
			cout << "0" << endl;
			continue;
		}
		ll inevitable = prefDamage[n] - prefDamage[indx - 1];
		inevitable %= modik2;
		ll rest = prefDamage[indx - 1];
		inevitable = (inevitable + modik2) % modik2;
		ll p1 = (attacks - durability)*powik(attacks);
		p1 %= modik2;
		ll p2 = (attacks+1 - durability)*powik(attacks+1);
		p2 %= modik2;
		ll ans = (((p1*inevitable) % modik2) + ((p2*rest) % modik2)) % modik2;
		cout << ans << endl;

	}
	return 0;
}

ll powik(ll number, ll power)
{
	if (!power)
	{
		return 1ll;
	}
	if (power % 2)
	{
		return (number*(powik(number, power - 1) % modik2)) % modik2;
	}
	else
	{
		ll ret = (powik(number, power / 2) % modik2);
		return (ret*ret) % modik2;
	}
}
