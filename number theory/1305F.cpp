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
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-14;

int n;
ll tab[maxik];
const ll tempmax = 1e17;
ll ans = tempmax;
ll checkfordiv(ll num);
ll checkall(ll num);
int main()
{
	es;
	//TXT;
	randomizer;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
	}
	int randek = 20;
	while (randek--)
	{
		int indx = (rng() % n) + 1;
		if (tab[indx]>1)
		{
			ans = min(ans, checkfordiv(tab[indx ]-1ll));
		}
		ans = min(ans, checkfordiv(tab[indx]));
		ans = min(ans, checkfordiv(tab[indx] + 1ll));
	}
	cout << ans << endl;
	return 0;
}
ll checkfordiv(ll num)
{
	ll ret = 1e17;
	ll sqerek = sqrt(num + 1ll);
	for (int i = 2; i <= sqerek; i++)
	{
		if (!(num%i))
		{
			ret = min(ret, checkall(i));
			while (!(num%i))
			{
				num /= i;
			}
			if (num == 1)
			{
				break;
			}
		}
	}
	if (num > 1)
	{
		ret = min(ret, checkall(num));
	}
	return ret;
}
ll checkall(ll num)
{
	ll ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ll rem = tab[i] % num;
		if (tab[i] == rem)
		{
			ret += num - rem;
		}
		else
		{
			ret += min(num - rem, rem);
		}
	}
	return ret;
}
