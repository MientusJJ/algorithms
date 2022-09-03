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
const int maxik = 1e5 + 7;
const int maxN = 2010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
int n;
pii tab[maxik];
int maxY; int minY;
bool check(double mid);
int main()
{
	es;
	cin >> n;
	maxY = minY = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i].x >> tab[i].y;
		maxY = max(maxY, tab[i].y);
		minY = min(minY, tab[i].y);
		tab[i].y = fabs(tab[i].y);
	}
	if (maxY > 0 && minY < 0)
	{
		cout << "-1";
		return 0;
	}
	int cases = 500;
	long double lR = 0, rR = 1e14 + 7;
	while (cases--)
	{
		long double mid = (lR + rR) / 2.0;
		if (check(mid))
		{
			rR = mid;
		}
		else
		{
			lR = mid;
		}
	}
	prec(10);
	cout << rR;
	return 0;
}
bool check(double r)
{
	long double maxR = -1e15,minR=1e15;
	for (int i = 1; i <= n; i++)
	{
		if (2*r < (tab[i].y))
		{
			return false;
		}
		long double ll = (2*r-tab[i].y)*(tab[i].y);
		ll = sqrt(ll);
		long double left = tab[i].x + ll;
		long double right = tab[i].x - ll;
		maxR = max(maxR, right);
		minR = min(minR, left);
	}
	return minR >= maxR;
}
