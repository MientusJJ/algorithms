#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int maxik = 1e5;
int tab[maxik + 7];
int ans = INF;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int w, l;
	cin >> w >> l;
	for (int i = 1; i <w; i++)
	{
		cin >> tab[i];
		tab[i] += tab[i - 1];
	}
	for (int i = l; i < w; i++)
	{
		ans = min(ans, tab[i] - tab[i - l]);
	}
	cout << ans;
	return 0;
}
