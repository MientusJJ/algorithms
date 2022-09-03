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
#include <stack>
#define es ios::sync_with_stdio(false);cin.tie(0);
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 1e5 + 9;
const int maxN = 3010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int sMOD = 998244353;
string s;
string t;
int n;
ll dp[maxN][maxN];
ll ans = 0;
int main()
{
	es;
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	int m = t.size()-1;
	int n = s.size() - 1;
	{
	for (int i = 1; i <= n; i++)
		dp[i][i] = (i > m || s[1] == t[i]) ? 2 : 0;
	}
	for (int indx = 2; indx <= n; indx++)
	{
		for (int l = 1; l + indx-1 <= n; l++)
		{
			int r = l + indx - 1;
			if (l > m || s[indx] == t[l])
			{
				dp[l][r] += dp[l + 1][r];
				dp[l][r] %= sMOD;
			}
			if (r > m || s[indx] == t[r])
			{
				dp[l][r] += dp[l][r-1];
				dp[l][r] %= sMOD;
			}
		}
	}
	for (int i = m; i <= n; i++)
	{
		ans += dp[1][i];
		ans %= sMOD;
	}
	cout << ans;
	return 0;
}
