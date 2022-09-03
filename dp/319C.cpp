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
const int maxik = 1e5 + 9;
const int maxN = 2010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

ll dp[maxik];
ll a[maxik], b[maxik];
long double slope(ll d, ll c) {
	long double r = (dp[c] - dp[d]); long double z = (b[d] - b[c]);
	return r / z;
}
ll n;
ll head = 1, tail = 1;
ll q[maxik];
int main()
{
	es;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	head = tail = 1;
	q[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		while (head<tail && slope(q[head],q[head+1])<a[i] )
		{
			head++;
		}
		dp[i] = dp[q[head]] + a[i] * b[q[head]];
		while (head < tail && slope(q[tail - 1], q[tail]) > slope(q[tail], i))
		{
			tail--;
		}
		tail++;
		q[tail] = i;
	}

	cout << dp[n];
	return 0;
}
