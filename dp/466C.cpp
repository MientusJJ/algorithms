#include <iostream>

using namespace std;
const int maxik = 5e5;
typedef long long ll;
ll dp[maxik + 7];
ll result = 0;
ll littleResult;
ll firstParagraph, secondParagraph;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}
	if (dp[n] % 3 || n < 3)
	{
		cout << result;
	}
	else
	{
		firstParagraph = dp[n] / 3;
		secondParagraph = firstParagraph * 2;
		for (int i = 1; i <= n; i++)
		{
			if (dp[i] == firstParagraph)
			{
				++littleResult;
			}
			else if (dp[i] == secondParagraph)
			{
				result += littleResult;
			}
		}
		if (dp[n] == 0)
		{
			result = (littleResult-1) *(littleResult-2)/2;
		}
		cout << result;
	}
	//system("pause");
}
