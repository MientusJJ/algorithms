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
const int maxik = 1e5+7;
const int maxValue = 30;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

int tab[maxik], dp[maxik];
int n, ans = 0;
int kadane();
int main()
{
	es;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
	}
	for (int i = maxValue;i>=1;i--)
	{
		for (int j = 1; j <= n; j++)
		{
			if (tab[j] > i)
			{
				dp[j] = -INF;
			}
			else
			{
				dp[j] = tab[j];
			}
		}
		ans = max(ans, kadane() - i);
	}
	cout << ans;
	return 0;
}
int kadane()
{
	int ret = 0,temp=0;
	for (int i = 1; i <= n; i++)
	{
		 temp = max(temp + dp[i], dp[i]);
		 ret = max(ret, temp);
	}
	return ret;
}
