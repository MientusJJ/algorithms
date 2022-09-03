#include <iostream>
#include <algorithm>
using namespace std;
const int maxik = 1e5;
typedef long long ll;
ll tab[maxik + 7];
int maximus = 0;
int main()
{
	int n;
	int number;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		maximus = max(maximus, number);
		tab[number] += number;
	}
	for (int i = 2; i <= maximus; i++)
	{
		tab[i] = max(tab[i] + tab[i - 2], tab[i - 1]);
	}
	cout << tab[maximus];
}
