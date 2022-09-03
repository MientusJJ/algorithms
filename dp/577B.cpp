#include <iostream>

using namespace std;
using ll = long long;
const int maxik = 1e6,divis=1001;
ll tab[maxik + 7];
bool dp[divis][divis];
bool es = false;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int number, mopadulo;
	cin >> number >> mopadulo;
	for (int i = 1; i <= number; i++)
	{
		cin >> tab[i];
		tab[i] %= mopadulo;
	}
	if (number >= mopadulo)
	{
		cout << "YES";
	}
	else
	{
		for (int i = 1; i <= number; i++)
		{
			dp[i][tab[i] % mopadulo] = 1;
			for (int j = 0; j < mopadulo; j++)
			{
				if (dp[i - 1][j])
				{
					dp[i][j] = 1;
					dp[i][(j + tab[i]) % mopadulo] = 1;
				}
			}
		}
		bool tcout = false;
		for (int i = 1; i <= number; i++)
		{
			if (dp[i][0])
			{
				tcout = true;
				break;
			}
		}
		if (tcout)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}

	//system("pause");
}
