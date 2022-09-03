#include <iostream>

using namespace std;
const int modulo = 1e9 + 7;
const int maxik=100;
typedef long long ll;
typedef pair<ll, ll> parka;
parka tab[maxik + 7];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, d;
	cin >> n >> k >> d;
	tab[0].first = 1; tab[0].second =0 ;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i >= j)
			{
				if (j >= d)
				{
					tab[i].second += tab[i - j].first + tab[i - j].second;
					tab[i].second %= modulo;
				}
				else
				{
					tab[i].second += tab[i - j].second;
					tab[i].second %= modulo;
					tab[i].first += tab[i - j].first;
					tab[i].first %= modulo;
				}
			}
		}
	}
	tab[n].second%=modulo;
	cout << tab[n].second;
}
