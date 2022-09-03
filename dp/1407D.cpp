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
const int maxik = 3e5+9;
const int maxN = 2010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

int dp[maxik];
int n;
int skycraps[maxik];
stack<int> maximus;
stack <int> minimus;
int main()
{
	es;
	cin >> n;
	cin >> skycraps[1];
	maximus.push(1);
	minimus.push(1);

	for (int i = 2; i <= n; i++)
	{
		cin >> skycraps[i];
		dp[i] = dp[i - 1]+1;
		while (maximus.size() && skycraps[maximus.top()]>=skycraps[i])
		{
			int temp = skycraps[maximus.top()];
			maximus.pop();
			if (skycraps[i] < temp && maximus.size())
			{
				dp[i] = min(dp[i], dp[maximus.top()] + 1);
			}
		}
		maximus.push(i);
		while (minimus.size() && skycraps[minimus.top()] <= skycraps[i])
		{
			int temp = skycraps[minimus.top()];
			minimus.pop();
			if (skycraps[i] > temp && minimus.size())
			{
				dp[i] = min(dp[i], dp[minimus.top()] + 1);
			}
		}
		minimus.push(i);
	}

	cout << dp[n];
	return 0;
}
