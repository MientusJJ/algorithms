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
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int maxik = 1e6 + 9;
const int maxN = 2010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

struct rectangle
{
	bool operator<(const  rectangle &r)
	{
		if (this->x != r.x)
		{
			return this->x < r.x;
		}
		else
		{
			return this->y < r.y;
		}
	}
	int x;
	int y;
	ll area;
};

int n;
ll dp[maxik];
rectangle rec[maxik];
ll ans = -INF;
int que[maxik];
int head, tail;
ld slope(int j, int k)
{
	return ((1.0)*(dp[j] - dp[k])) / (1.*(rec[j].x - rec[k].x));
}
int main()
{
	es;
	head = tail =1 ;
	que[head] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> rec[i].x >> rec[i].y >> rec[i].area;
	}
	sort(rec + 1, rec + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1ll * (rec[i].x)*rec[i].y - rec[i].area;
		ans = max(dp[i], ans);
	}
	
	for (int i =2 ; i <= n; i++)
	{
		while (head < tail && (slope(que[head+1], que[head]) > rec[i].y))
		{
			head++;
		}
		dp[i] = max(dp[i],dp[i]+dp[que[head]] - 1ll*rec[i].y*rec[que[head]].x);
		ans = max(dp[i], ans);
		while (head < tail && slope(i, que[tail]) > slope(que[tail], que[tail-1]))
		{
			tail--;
		}
		que[++tail] = i;
	}
	cout << ans;
	return 0;
}
