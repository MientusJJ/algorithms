#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
ll bags[64];
void solve();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}
	return 0;
	//system("pause");
}
void solve()
{
	ll ans=0;
	ll sum = 0, n, m, one, packed = 0,hm=0;
	memset(bags, 0, sizeof bags);
	cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		cin >> one;
		sum += one;
		ll j = 0;
		while ((one >> j))
		{
			j++;
		}
		bags[j-1]++;
	}
	if (sum < n)
	{
		cout << "-1" << "\n";
		return;
	}
	for (ll i = 0; i <= 60; i++)
	{
		hm += bags[i] * (1 << i);
		if ((n >> i) & 1)
		{
			//ll hm = 0;
		
			
			if (hm - packed >= (1 << i))
			{
				packed += (1 << i);
			}
			else
			{
				ll div = -1;
				for (ll j = i + 1; j <= 60; j++)
				{
					if (bags[j])
					{
						div = j;
						break;
					}
				}
				ans += div - i;
				bags[div]--;
				for (ll j = div - 1; j >= i; j--)
				{
					bags[j]++;
				}
				bags[i]++;
				hm += (1 << (i+1));
				packed += (1 << i);
			}
		}
	}
	cout << ans << "\n";
	return;
}
