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
//#define TXTcreate freopen("C:/Temp/output.txt","w",stdout);freopen("input.txt","w",stdout);
#define TXT  freopen("C:/Temp/input.txt","r",stdin); freopen("C:/Temp/output.txt","w",stdout);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 2e5+7;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-14;

ll powik(ll number, ll power = modik - 2)
{
	if (!power)
	{
		return 1ll;
	}
	if (power % 2)
	{
		return (number*(powik(number, power - 1) % modik)) % modik;
	}
	else
	{
		ll ret = (powik(number, power / 2) % modik);
		return (ret*ret) % modik;
	}
}

int n;
ll l[maxik];
ll r[maxik];
ll p[maxik];
ll q[maxik];
ll ans = 0;
ll sumP = 1;
ll expec(int ind);
int main()
{
	es;
	//TXT;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> r[i];
	}
	memset(p, 0ll, sizeof p);
	memset(q, 0ll, sizeof q);
	p[1] = 1ll;
	for (int i = 2; i <= n; i++)
	{
		ll range = max(0ll, min(r[i], r[i - 1]) + 1 - max(l[i], l[i - 1]));
		ll deno = (r[i] - l[i] + 1)*(r[i - 1] - l[i - 1] + 1) % modik;
		q[i] = (range * powik(deno)) % modik;
		p[i] = ((ll)((ll)modik + 1 - q[i])) % modik;
		sumP += p[i];
		sumP %= modik;
	}
	for (int i = 1; i <=n; i++)
	{
		ll temp = 0;
		for (int j = max(0, i - 1); j <= min(n, i + 1); j++)
		{
			temp += p[j];
			temp%=modik;
		}
		sumP -= temp;
		sumP += modik;
		sumP %= modik;
		ans += p[i] + (p[i] * sumP) % modik;
		ans%=modik;
		sumP += temp;
		sumP%=modik;
		ans%=modik;
		if (i > 1)
		{
			ans += expec(i);
			ans %= modik;
		}
		if (i < n)
		{
			ans += expec(i + 1);
			ans %= modik;
		}

	}
	cout << ans << endl;
	return 0;
}
ll expec(int ind)
{
	int ind2 = ind - 1;
	ll ret=1;
	ret -= q[ind];
	ret = (ret + modik) % modik;
	ret -= q[ind-1];
	ret = (ret + modik) % modik;
	ll range = max(0ll, min(r[ind], min(r[ind+1],r[ind - 1])) + 1 - max(l[ind], max(l[ind - 1],l[ind+1])));
	ll deno= ((((r[ind] - l[ind] + 1)*(r[ind - 1] - l[ind - 1] + 1)) % modik)*(r[ind + 1] - l[ind + 1] + 1))%modik;
	ret += (range*powik(deno)) % modik;
	return ret;
}
