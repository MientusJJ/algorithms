#include <iostream>
#include <algorithm>
using namespace std;
const int maxik = 5000;
int mainTab[maxik + 7];
int scale[maxik + 7];
int dp[maxik + 3][maxik + 3];
//int leftIndex[maxik + 7];
//int rightIndex[maxik + 7];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, hm = 2;
	cin >> n;
	cin >> mainTab[1];
	for (int i = 2; i <= n; i++)
	{
		cin >> mainTab[hm];
		if (mainTab[hm] != mainTab[hm - 1])
		{
			hm++;
		}
	}
	hm--;
	for (int s = 1; s < hm; s++)
	{
		for (int lIndx = 1; lIndx <= hm - s; lIndx++)
		{
			int rIndx = s + lIndx;
			if (mainTab[lIndx] == mainTab[rIndx])
			{
				dp[lIndx][rIndx] = dp[lIndx + 1][rIndx - 1]+1;
			}
			else
			{
				dp[lIndx][rIndx] = 1 + min(dp[lIndx + 1][rIndx], dp[lIndx][rIndx - 1]);
			}
		}
	}
	cout << dp[1][hm];
	system("pause");
}
