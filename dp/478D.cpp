#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 2e5 + 7;
const int maxN = 2000;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

int r, g, f, h;
ll dp[maxik];
ll tower[maxik];
ll ans = 0;
int main()
{
	es;
	tower[0] = 0;
	dp[0]= 1;
	cin >> r >> g;
	f = r + g;
	for (int i = 0; i <= maxik;i++)
	{
		tower[i] = tower[i - 1] + i;
	
		if (tower[i] > f )
		{
			h = i - 1;
			break;
		}
	}
	for (int i = 1; i <= h; i++)
	{
		for (int rr = r; rr >= 0; rr--)
		{
			
			if (rr - i < 0) break;
			dp[rr] += dp[rr-i];
			dp[rr] %= modik;
		}
	}
	for (int i = 0; i <= r; i++)
	{
		if (tower[h] - i <= g)
		{
			ans += dp[i];
			ans %= modik;
		}
	}
	cout << ans;
	return 0;
}
