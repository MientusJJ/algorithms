#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define maxik 5007
#define INF 0x4f4f4f4f
#define es ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll = long long;
int dp[maxik];
int n;
int solve(int l, int r);
int main()
{
	es;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i];
	}
	cout << solve(1, n);
	return 0;
}
int solve(int l, int r)
{
	if (r < l) return 0;
	int ans = 0, minek = INF;
	for (int i = l; i <= r; i++)
	{
		minek = min(minek, dp[i]);
	}
	if (minek > 0)
	{
		ans += minek;
		for (int i = l; i <= r; i++)
		{
			dp[i] -= minek;
		}
	}
	int ll = l;
	for (int i = l; i <= r; i++)
	{
		if (!dp[i])
		{
			ans += solve(ll, i - 1);
			ll=i+1;
		}
		else if (i == r)
		{
			ans+=solve(ll, r);
		}
	}

	return min(ans, r - l + 1);
}
