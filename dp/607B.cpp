#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1.5e9;
const int maxik = 507;
int dp[maxik][maxik];
int tab[maxik];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == i)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = inf;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (tab[i] == tab[i + 1])
		{
			dp[i][i + 1] = 1;
		}
		else
		{
			dp[i][i + 1] = 2;
		}
	}
	for (int indx = 2; indx <= n - 1; indx++)
	{
		for (int l = 1; l + indx <= n; l++)
		{
			int r = l + indx;
			dp[l][r] = min(dp[l][r], dp[l + 1][r] + 1);
			if (tab[l] == tab[r])
			{
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
			}
			if (tab[l] == tab[l + 1])
			{
				dp[l][r] = min(dp[l][r], 1 + dp[l + 2][r]);
			}
			for (int t = l + 2; t < r; t++)
			{
				if (tab[l] == tab[t])
				{
					dp[l][r] = min(dp[l][r], dp[l+1][t - 1] + dp[t + 1][r]);
				}
			}
		}
	}
	cout << dp[1][n];
	//system("pause");
}
