#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const string T = "T";
const string HL = "HL";
const int maxik = 100;
int tab[maxik + 7];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, ans, n,sum;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		int biggest = 0;
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			cin >>tab[j];
			biggest = max(biggest, tab[j]);
			sum += tab[j];
		}
		if (n==1 || biggest>sum-biggest)
		{
			cout << T << "\n";
		}
		else
		{
			if (sum % 2)
			{
				cout << T;
			}
			else
			{
				cout << HL;
			}
			cout << "\n";
		}
	}
	//system("pause");
}
