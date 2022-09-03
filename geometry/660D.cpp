#include <iostream>
#include <map>

using namespace std;
const int maxik = 2000;
using parka = pair<int, int>;
struct point
{
	int x;
	int y;
};
point tab[maxik+7];
int result = 0;
map<parka,int> es;
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
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			result += es[{ tab[i].x + tab[j].x,tab[i].y + tab[j].y }];
			es[{ tab[i].x + tab[j].x,tab[i].y + tab[j].y }]++;
		}
	}
	cout << result;
}
