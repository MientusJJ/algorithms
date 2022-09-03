#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxik = 3007;

struct player {
	int sport, programming, index;
	bool operator<(const player &b)
	{
		if (this->programming != b.programming)
		{
			return this->programming > b.programming;
		}
		return this->sport > b.sport;
	}
};

int n, p, s;
int dp[maxik][maxik], trace[maxik][maxik];
vector<int> prog, sport;
player tab[maxik];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> p >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i].programming;
		tab[i].index = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i].sport;
	}
	sort(tab + 1, tab + 1 + n);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i <= p)
		{
			dp[i][0] = dp[i - 1][0] + tab[i].programming;
		}
		else
		{
			dp[i][0] = dp[i - 1][0];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			if (dp[i - 1][j - 1] + tab[i].sport > dp[i][j])
			{
				dp[i][j] = dp[i - 1][j - 1] + tab[i].sport;
				trace[i][j] = j - 1;
			}
			if (dp[i - 1][j] == -1) break;
			if (((i - j) <= p) && dp[i - 1][j] + tab[i].programming > dp[i][j])
			{
				dp[i][j] = dp[i - 1][j] + tab[i].programming;
				trace[i][j] = j;
			}
			else if ((i - j) > p && dp[i][j] < dp[i - 1][j])
			{
				dp[i][j] = dp[i - 1][j];
				trace[i][j] = j;
			}
		}
	}
	cout << dp[n][s] << "\n";
	int j = s;
	for (int i = n; i >= 1; i--)
	{
		if (j > trace[i][j])
		{
			prog.push_back(tab[i].index);
		}
		else if (i - j <= p)
		{
			sport.push_back(tab[i].index);
		}
		j = trace[i][j];
	}
	sort(prog.begin(), prog.end());
	sort(sport.begin(), sport.end());

	for (int i = 0; i < sport.size(); i++)
	{
		cout << sport[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < prog.size(); i++)
	{
		cout << prog[i] << " ";
	}
	return 0;
}
