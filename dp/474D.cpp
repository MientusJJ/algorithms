#include <iostream>

using namespace std;
using ll = long long;
const int modulo = 1000000007;
const int  maxik = 1e5;
ll dp[maxik + 7];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, k;
	cin >> t >> k;
	int i = 0;
	while (i<k)
	{
		dp[i] = 1;
		i++;
	}
	for (int i=k; i < maxik + 5; i++)
	{
		dp[i] = dp[i - 1] + dp[i - k];
		dp[i] %= modulo;
	}
	for (int i = 1; i <= maxik + 4; i++)
	{
		dp[i] += dp[i - 1];
		dp[i] %= modulo;
	}
	for (int j = 0; j < t; j++)
	{
		int l, r;
		cin >> l >> r;
		ll cut = dp[r] - dp[l - 1];
		cut %= modulo;
		if (cut < 0) cut += modulo;
		cout << cut << "\n";
	}
	//system("pause");
}
