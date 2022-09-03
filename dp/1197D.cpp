#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxik = 3e5;
const int divide = 10;
int tab[maxik+7];
ll dp[maxik + 7][divide + 1];
 ll result = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			dp[i][j] = -1e9;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
		dp[i][1 % m] = tab[i] - k;
		result = max(result, dp[i][1 % m]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			int left = j - 1 + m;
			left %= m;
			if (left)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][left] + tab[i]);
			}
			else
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][left] + tab[i]-k);
			}
			result = max(dp[i][j], result);
		}
	}
	cout << result;
}
