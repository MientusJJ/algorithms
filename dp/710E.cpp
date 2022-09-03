#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <string>
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
const int maxik = 1e6 + 7;
const int maxN = 1e7+7;
const int INF = 0x3f3f3f3f;
const ll INFll = (1LL<<60);
const int modik = 1e9 + 7;

ll dp[maxN];
int n, x, y;
int main()
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n+5; i++)
	{
		dp[i] = INFll;
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = min(dp[i - 1] + x,min(dp[i],dp[i+1]+x));
		if (i*2<=n+1)
		{
			dp[i * 2] = min(dp[i]+y, dp[i * 2]);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}
