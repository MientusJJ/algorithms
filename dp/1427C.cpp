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
const int maxik = 1e5 + 7;
const int maxValue = 30;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

struct celebrity
{
	int time, x, y;
	int operator-(const celebrity &c)
	{
		return this->time - c.time;
	}
};
int ans = 0;
int dp[maxik];
celebrity cb[maxik];
int start = -1;
int r, n;
int inline makeCalc(celebrity &a, celebrity &b);
int main()
{
	es;
	cin >> r >> n;
	cb[0].x = cb[0].y = 1;
	cb[0].time = dp[0] = 0;
	r *= 4;
	for (int i = 1; i <= n; i++)
	{
		cin >> cb[i].time >> cb[i].x >> cb[i].y;
		if (i >= r)
		{
			start = max(start, dp[i - r]);
		}
		dp[i] = start;
		for (int j = max(0, i - r); j < i; j++)
		{
			if (dp[j]!=-1 &&(makeCalc(cb[j], cb[i]) <= (cb[i] - cb[j])))
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
int  makeCalc(celebrity &a, celebrity &b)
{
	int aa = abs(a.y - b.y);
	int bb = abs(a.x - b.x);
	return aa + bb;
}
