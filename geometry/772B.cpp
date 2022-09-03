#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
const int maxik = 1e3+2;
const double acc = 1e-7;
struct point
{
	double x;
	double y;
	point()
	{
		this->x = 0;
		this->y = 0;
	}
	point(double xx, double yy)
	{
		x = xx;
		y = yy;
	}

};
double distance(point a, point b);
double result = -1.0;
double solve(point a, point b, point c);
double area(point a, point b);
double turn(double a);

point tab[maxik + 7];
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
	tab[n + 1] = tab[1];
	tab[n + 2] = tab[2];
	for (int i = 1; i <= n; i++)
	{
		point a, b;
		a.x = (tab[i].x + tab[i + 1].x) / 2;
		b.x = (tab[i+2].x + tab[i + 1].x) / 2;
		a.y = (tab[i].y + tab[i + 1].y) / 2;
		b.y = (tab[i + 2].y + tab[i + 1].y) / 2;
		double temp = solve(a, b, tab[i + 1]);
		if (result < 0)
		{
			result = temp;
		}
		else
		{
			result = min(result, temp);
		}
	}
	cout <<fixed << setprecision(10) << result;
	//system("pause");
}
double distance(point a, point b)
{
	double temp = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	temp = sqrt(temp);
	return temp;
}
double solve(point a, point b, point c)
{
	double ret;
	double dist = distance(a, b);
	point v1 (c.x - b.x,c.y-b.y);
	point v2(c.x - a.x, c.y - a.y);
	double ar = area(v1,v2);
	ar = turn(ar);
	ret = ar / (dist);
	return ret;
}
double area(point a, point b)
{
	return (a.x*b.y - a.y*b.x);
}

double turn(double a)
{
	if (a < 0)
	{
		return -a;
	}
	return a;
}
