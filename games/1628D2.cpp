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
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define Y cout << "YES" << "\n";
#define N cout << "NO" << "\n";
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxik = 1e6;
const int maxN = 1e6+7;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

ll sil[maxN];
ll invsil[maxN];
ll p2[maxN];
ll powik(ll a, ll b = modik - 2);
void solve();
ll value(ll n, ll k);
ll n, m, k, t;
int main()
{
	es;
	cin >> t;
	sil[0] = 1;
	p2[0] = 1;
	for (int i = 1; i <= maxik; i++)
	{
		sil[i] = (sil[i - 1] * i) % modik;
		p2[i] = (p2[i - 1] * 2) % modik;
	}
	invsil[maxik] = powik(sil[maxik]);
	for (int i = maxik - 1; i+1; i--)
	{
		invsil[i] = (invsil[i + 1] * (i + 1)) % modik;
	}
	while (t--)
	{
		cin >> n >> m >> k;
		solve();
	}
	return 0;
}
ll powik(ll a,ll b)
{
	if (b <= 0)
	{
		return 1;
	}
	if (b % 2)
	{
		ll res = (powik(a, b - 1)%modik);
		return ((res*a) % modik);
	}
	else 
	{
		ll res = (powik(a, b / 2) % modik);
		return ((res*res) % modik);
	}
}
void solve()
{
	if (n == m)
	{
		cout << (n*k) % modik << "\n";
		return;
	}
	if (!m)
	{
		cout << "0\n";
		return;
	}
	ll ans = 0;
	for (int i = m; i; i--)
	{
		ans += i % modik*powik(powik(2,n-i)) % modik*value(n - 1 - i, m - i) % modik;
		ans %= modik;
	}
	ans *= k;
	ans%=modik;
	cout << ans << "\n";
	return;
}
ll value(ll n, ll k)
{
	if (k > n)
	{
		return 0;
	}
	if (!n || !k)
	{
		return 1;
	}
	ll ret = sil[n] % modik;
	ret *= invsil[k];
	ret %= modik;
	ret *= invsil[n - k];
	ret %= modik;
	return ret;
}
