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
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
#define TXTcreate freopen("output.txt","w",stdout);freopen("input.txt","w",stdout);
#define TXT  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxik = 1e5 + 7;
const int maxN = 1 << 20;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
ll Newton(int n, int k);
ll invNewton(int n, int k);
ll powik(ll number, ll power = modik - 2)
{
	if (!power)
	{
		return 1ll;
	}
	else
	{
		if (power%2)
		{
			return ((number%modik * powik(number, power - 1)%modik)%modik);
		}
		else
		{
			ll temp = powik(number, power / 2);
			temp %= modik;
			return ((temp*temp) % modik);
		}
	}
}

ll sil[maxik];
ll invsil[maxik];
int t, n, k;
void solve();
int main()
{
	es;
	//TXT;
	sil[0] = 1;
	for (int i = 1; i < maxik; i++)
	{
		sil[i] = sil[i - 1] * i;
		sil[i] %= modik;
	}
	invsil[maxik - 1] = powik(sil[maxik - 1]);
	for (int i = maxik-2; i>= 0; i--)
	{
		invsil[i] = invsil[i + 1] * (i + 1);
		invsil[i] %= modik;
	}
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
void solve()
{
	cin >> n >> k;
	ll ans = 1;
	for (int i = 1; (k - 1)*(i - 1) <= n; i++)
	{
		ans += (Newton(n - (k - 1)*(i - 1), i)*invNewton(n, i)) % modik;
		ans %= modik;
	}
	cout << ans << "\n";
	return;
}
ll Newton(int n, int k)
{
	if (n < k) return 0ll;
	return (1ll*(sil[n] * invsil[n - k]) % modik * invsil[k])%modik;

}
ll invNewton(int n, int k)
{
	if (n < k) return 0ll;
	return (1ll * (invsil[n] * sil[n - k])%modik * sil[k]) % modik;
}
