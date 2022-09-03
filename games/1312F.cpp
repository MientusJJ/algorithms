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
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
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
const int maxik = 1e3 + 7;
const int maxN = 5e2;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
int tab[maxik][3];
int t, n, x, y, z;
int val(ll a, int b);
void init();
ll cav(ll i);
ll infa(ll i);
ll mixed(ll i);
int mex(int a, int b, int c);
int len = 0;
vector<ll> v;
int main()
{
	es;
	cin >> t;
	while (t--)
	{
		v.clear();
		cin >> n >> x >> y >> z;
		memset(tab, 0, sizeof tab);
		init();
		v.resize(n + 1);
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++)
		{
			res ^= val(v[i], 0);
		}
		//cout << "ODP: ";
		if (res == 0)
		{
			cout << "0\n"; continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			res ^= val(v[i], 0);
			if (!(res^val(mixed(v[i]), 0)))
			{
				ans++;
			}
			if (!(res^val(cav(v[i]), 1)))
			{
				ans++;
			}
			if (!(res^val(infa(v[i]), 2)))
			{
				ans++;
			}

			res ^= val(v[i], 0);
		}
		cout << ans << "\n";
	}
	return 0;
}

void init()
{
	for (int i = 1; i <= 1000; i++)
	{
		tab[i][0] = mex(tab[mixed(i)][0], tab[cav(i)][1], tab[infa(i)][2]);
		tab[i][1] = mex(tab[mixed(i)][0], 3, tab[infa(i)][2]);
		tab[i][2] = mex(tab[mixed(i)][0], tab[cav(i)][1], 3);
		if (i > maxN)
		{
			bool flag = 1;
			for (int k = 0; k < 5; k++)
			{
				if (tab[i - k][0] != tab[maxN - k][0] || tab[i - k][1] != tab[maxN - k][1] || tab[i - k][2] != tab[maxN - k][2])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				len = i - maxN;
				break;
			}
		}
	}
	return;
}
int mex(int a, int b, int c)
{
	int res = 0;
	set<int> s;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	while (s.count(res))
	{
		res++;
	}
	return res;
}
ll cav(ll i)
{
	if (i - z < 0)
	{
		return 0ll;
	}
	return ll(i - z);
}
ll infa(ll i)
{
	if (i - y < 0)
	{
		return 0ll;
	}
	return ll(i - y);
}
ll mixed(ll i)
{
	if (i - x < 0)
	{
		return 0ll;
	}
	return ll(i - x);
}
int val(ll a, int b)
{
	if (a <= maxN) return tab[a][b];
	int temp = (a - maxN) % len + maxN;
	return tab[temp][b];
}
