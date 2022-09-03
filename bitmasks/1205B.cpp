#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxik = 62;
const int maxTab = 1e5;
const ll maxRes = 1e9 + 7;
const int maxD = 200;
int bits[maxik+7];
int flags[maxTab + 7];
ll tab[maxTab + 7];
ll dist[maxD][maxD];
ll Waves[200];
int conn[200][200];
ll res;
int main()
{
	cin.tie(0);
	ll res = maxRes;
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
		for (int j = 0; j < maxik; j++)
		{
			if ((1ll << j)& tab[i])
			{
				bits[j+1]++;
				flags[i]++;
			}
		}
	}
	bool is = false;
	for (int i = 1; i <= maxik; i++)
	{
		if (bits[i] >= 3)
		{
			is = true;
			break;
		}
	}
	if (is)
	{
		cout << "3";
		return 0;
	}
	int wo = 0;
	for (int i = 1; i <= n; i++)
	{
		if (flags[i]>=2)
		{
			Waves[++wo] = tab[i];
		}
	}
	for (int i = 1; i <= wo; i++)
	{

		for (int j = 1; j <=wo; j++)
		{
			dist[i][j] = maxRes;
			conn[i][j] = maxRes;

			if (j!=i &&Waves[i]&Waves[j])
			{
				dist[i][j]= 1;
				conn[i][j] = 1;
			}
		}
	}
	
	for (int k = 1; k <= wo; k++)
	{
		for (int i = 1; i <= wo; i++)
		{
			for (int j = i+1; j <= wo; j++)
			{
				res = min(res, dist[i][j] + conn[j][k] + conn[k][i]);
			}
		}
		for (int j = 1; j <= wo; j++)
		{
			for (int i = 1; i <= wo; i++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	if (res != maxRes)
	{
		cout << res;
	}
	else
	{
		cout << "-1";
	}
	return 0;
}
