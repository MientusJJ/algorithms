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
const int maxik = 2e5+9;
const int maxN = 2010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

ll pref[maxik], sufix[maxik];
ll ans;

int main()
{
	es;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> pref[i];
		sufix[i] = pref[i];
	}
	for (int i = 3; i <= n; i++)
	{
		pref[i] += pref[i - 2];
	}
	for (int i=n-2;i>=1;i--)
	{
		sufix[i] += sufix[i + 2];
	}
	for (int i = 0; i <= n; i++)
	{
		ans = max(ans, pref[i] + sufix[i + 1]);
	}
	cout << ans;
	return 0;
}
