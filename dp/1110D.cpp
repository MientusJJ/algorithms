#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 1e6+ 7;
const int maxN = 2000;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

int tab[maxik];
int dp[maxik][3][3];
int n, m, card;
int main()
{
	es;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> card;
		tab[card]++;
	}
	memset(dp, -1, sizeof dp);
	dp[0][0][0]=0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (dp[i - 1][j][k] < 0)
				{
					continue;
				}
				int cards = tab[i] - j - k;
				for (int p = 0; p < 3; p++)
				{
					if (p <= cards)
					{
						dp[i][k][p] = max(dp[i][k][p], dp[i - 1][j][k] + p + (cards - p) / 3);
					}
				}
			}
		}
	}
	cout << dp[m][0][0];
	return 0;
}
