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
#include <set>
#include <map>
#include <stack>
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define Y cout << "YES" << "\n";
#define N cout << "NO" << "\n";
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxik = 1e5 + 7;
const int maxN = 1e2;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;


int n,m,p;
ll d[maxik], cats[maxik],sum[maxik];
ll dp[maxik][maxN];
int que[maxik];
double slope(int pp, int indx1, int indx2);
int main()
{
	es;
	cin >> n >> m >> p;
	d[0] = d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		cin >> d[i];
		d[i] += d[i - 1];
	}
	for (int i = 1; i <= m; i++)
	{
		int hill;
		cin >> hill >> cats[i];
		cats[i] -= d[hill];
	}
	sort(cats + 1, cats + 1 + m);
	for (int i = 1; i <= m; i++)
	{
		sum[i] = sum[i - 1] + cats[i];
	}
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= p; j++)
		{
			dp[i][j] = 1e16;
		}
	}
	dp[0][0] = 0;
	for (int k = 1; k <= p; k++)
	{
		int head = 1;
		int tail = 1;
		que[1] = 0;
		for (int i = 1; i <= m; i++)
		{
			while (head < tail && slope(k,que[head],que[head+1])<cats[i])
			{
				head++;
			}
			dp[i][k] = min(dp[i][k], 1ll*dp[que[head]][k - 1] + 1ll*cats[i] * (i - que[head]) - (sum[i] - sum[que[head]]));
			while (head < tail && slope(k,que[tail-1],que[tail]) >slope(k, que[tail],i))
			{
				--tail;
			}
			que[++tail] = i;
		}
	}
	cout << dp[m][p];
	return 0;
}
double slope(int pp,int k,int j)
{
	double ret = 1. *(dp[j][pp - 1] - dp[k][pp - 1] + sum[j] - sum[k]);
	ret /= (1.*(j - k));
	return ret;
}
