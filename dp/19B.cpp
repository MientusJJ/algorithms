#include <iostream>
#include <vector>
#include <algorithm>
#define llmax 1000000000000000
using namespace  std;
using ll = long long;
const int maxik = 2e3;
struct product
{
	ll time;
	ll price;
};
bool compadre(product a, product b)
{
	return a.time > b.time;
}
ll dp[maxik + 7];
vector<product> v;
ll result;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = llmax;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].time >> v[i].price;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j >= 0; j--)
		{
			if (j >= v[i].time)
			{
				dp[j] = min(dp[j], dp[j - v[i].time-1] + v[i].price);
			}
			else
			{
				dp[j] = min(dp[j], v[i].price);
			}
		}
	}
	cout << dp[n];

}
