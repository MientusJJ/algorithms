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
const int maxik = 5e5 + 7;
//const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;

ll powik(ll number, ll power, ll modek = modik);
ll inv2 = modik / 2 + 1;
int n, k;
vector<ll> Stirl;
ll ans=0;
int main()
{
	es;
	//txt;
	cin >> n >> k;
	Stirl.resize(k + 1);
	Stirl[1] = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = i; j; j--)
		{
			Stirl[j] = Stirl[j - 1] + j * Stirl[j];
			Stirl[j] %= modik;
		}
	}
	ll fallingpower = 1;
	ll two = powik(2, n);
	for (int i = 1; i <= k; i++)
	{
		fallingpower *= (n - i + 1);
		fallingpower %= modik;
		two *= inv2;
		two %= modik;
		ans += ((Stirl[i] * fallingpower)%modik)*two;
		ans %= modik;
	}
	cout << ans << endl;
	return 0;
}
ll powik(ll number, ll power, ll modek)
{
	if (!power)
	{
		return 1ll;
	}
	if (power % 2)
	{
		return (number * powik(number, power - 1, modek))%modek;
	}
	else
	{
		ll p = powik(number, power/2, modek) % modek;
		return (p*p) % modek;
	}
}
