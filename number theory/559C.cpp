#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define es ios::sync_with_stdio(false);cin.tie(0);
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 2e5 + 7;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

ll odw(ll a);
ll ways(ll a, ll b);
ll powik(ll b, ll p);
ll tab[maxik];
ll dp[2007];
vector<pii> blacks;
int n, m;
int k;
int main()
{
	es;
	tab[0] = 1;
	cin >> n >> m >> k;
	for (int i = 1; i <= n + m; i++)
	{
		tab[i] = (tab[i - 1] * i) % modik;
	}
	blacks.rs(k + 1);
	for (int i = 0; i < k; i++)
	{
		cin >> blacks[i].x >> blacks[i].y;
		--blacks[i].x;
		--blacks[i].y;
	}
	blacks[k] = { n-1,m-1 };
	sort(all(blacks));
	for (int i = 0; i <= k; i++)
	{
		dp[i] = ways(blacks[i].x, blacks[i].y);
		for (int j = 0; j < i; j++)
		{
			if (blacks[i].x >= blacks[j].x &&blacks[i].y >= blacks[j].y)
			{
				dp[i] -= (dp[j] * ways(blacks[i].x - blacks[j].x, blacks[i].y - blacks[j].y)%modik);
				if (dp[i] > modik)
				{
					dp[i] -= modik;
				}
				else if (dp[i] < 0)
				{
					dp[i] += modik;
				}
			}
		}
	}
	cout << dp[k];
	return 0;
}
ll ways(ll a, ll b)
{
	return (((((tab[a + b] % modik)*(odw(tab[a]) % modik)) % modik)*(odw(tab[b]) % modik)) % modik);
}
ll odw(ll a)
{
	ll eul = modik - 2;
	return (powik(a, eul)%modik);
}
ll powik(ll b, ll p)
{
	if (!p) return 1;
	else if (p % 2 == 0)
	{
		ll res = powik(b, p / 2);
		return ((res*res) % modik);
	}
	else
	{
		return ((b*(powik(b, p - 1)%modik)) % modik);
	}
}
