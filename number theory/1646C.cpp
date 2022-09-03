#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <queue>
#define es ios::sync_with_stdio(false);cin.tie(0);
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 2e5 + 7;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;




int ones(ll a);
int t; ll n;
ll tab[16];
int main()
{
	tab[0] = tab[1] = 1;
	for(int i=2;i<=15;i++)
	{
		tab[i] = tab[i - 1] * i;
	}
	cin >> t;
	while (t--)
	{
		cin >> n;
		int ans=ones(n);
		for(int i=1;i<=(1<<15);i++)
		{
			int count = 0;
			ll sum = n;
			for(int j=0;j<15;j++)
			{
				if (i&(1 << j))
				{
					sum -= tab[j];
					count++;
				}
			}
			if (sum < 0)
			{
				continue;
			}
			ans = min(ans, (count + ones(sum)));
		}
		cout << ans << "\n";
	}
}
int ones(ll a)
{
	int count = 0;
	while (a)
	{
		if (a & 1)
		{
			count++;
		}
		a >>= 1;
	}
	return count;
}
