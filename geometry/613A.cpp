#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
const int maxik = 1e5;
const double pi = 3.14159265359;
struct point
{
	double x;
	double y;
};
double distance(point car, point x)
{
	return sqrt(((car.x - x.x)*(car.x - x.x)) + ((car.y - x.y)*(car.y - x.y)));
}
double makeD(point a, point b, point c);
double angle(point a, point b);
double maxi=-1, mini=-1;
point tab[maxik + 7];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	point car;
	double dist;
	int n;
	cin >> n;
	cin >> car.x >> car.y;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i].x >> tab[i].y;
	}
	tab[n + 1] = tab[1];
	for (int i = 1; i <= n; i++)
	{
		maxi = max(maxi, distance(car, tab[i]));
		dist = makeD(car, tab[i], tab[i + 1]);
		if (mini < 0) mini = dist;
		else mini = min(mini, dist);
	}
	cout << fixed << setprecision(10) << (maxi*maxi - mini*mini)*pi;
}
double makeD(point car, point b, point c)
{
	point v1, v2, v3;
	v1.x = car.x-b.x;
	v1.y = car.y-b.y;
	v2.x = c.x - b.x;
	v2.y = c.y - b.y;
	v3.x = car.x- c.x;
	v3.y =  car.y- c.y;
	if (angle(v1, v2) < 0)
	{
		return distance(car, b);
	}
	else if (angle(v2, v3) > 0)
	{
		return distance(car, c);
	}
	return fabs(v1.x*v2.y - v2.x*v1.y) / distance(b, c);
}
double angle(point a, point b)
{
	return a.x*b.x + b.y*a.y;
}
