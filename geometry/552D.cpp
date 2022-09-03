#include <iostream>
#include <vector>
#include <map>
#include <numeric>
using namespace std;
using ll = long long;
using parka = pair<int, int>;
const int maxik = 2000;
ll result = 0;
struct point
{
	int x; int y;
	point()
	{
		x = y = 0;
	}
	point(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
};
point tab[maxik + 7];
map<int, ll> es;
ll tempRes;
int line(point a, point b)
{
	int x = a.x - b.x;
	int y = a.y - b.y;
	if (y == 0) return 0;
	if (x == 0) return maxik * maxik + 7;
	int xdir,ydir;
	if (x > 0) xdir = 1;
	else xdir = -1;
	if (y > 0) ydir = 1;
	else ydir = -1;
	xdir *= ydir;
	ydir = 1;
	x = abs(x);
	y = abs(y);
	int d = gcd(x, y);
	x /= d;
	y /= d;
	ll temp= xdir * maxik*x + ydir * y;
	return temp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i].x >> tab[i].y;
	}
	result = (ll)n * (ll)(n - 1)*(ll)(n - 2) / 6;
	for (int i = 1; i <= n; i++)
	{
		es.clear();
		for (int j=1; j <= n; j++)
		{
			if (i != j)
			{
				es[line(tab[i], tab[j])]++;
			}
		}
		for (auto it = es.begin(); it != es.end(); it++)
		{
			tempRes += it->second*(it->second - 1) / 2;
		}

	}
	cout << result - (tempRes / 3);
	//system("pause");
}
