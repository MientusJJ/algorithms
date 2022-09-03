#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int maxik = 500;
char in[maxik + 7];
int dp[maxik + 7][maxik+7];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> in[i];
		dp[i][i] = 1;
	}
	if (n == 1)
	{
		cout << "1";
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (in[i] == in[i + 1])
		{
			dp[i][i + 1] = 1;
		}
		else
		{
			dp[i][i + 1] = 2;
		}
	}
	for (int indx = 2; indx < n; indx++)
	{
		for (int l = 1; l + indx <= n; l++)
		{
			int r = l + indx;
			if (in[l] == in[r]) dp[l][r] = dp[l + 1][r - 1] + 1;
			else
			{
				dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
			}
			for (int p = l;p <= r; p++)
			{
				dp[l][r] = min(dp[l][r], dp[l][p] + dp[p][r] - 1);
			}
		}
	}

	cout << dp[1][n];
	return 0;
}
