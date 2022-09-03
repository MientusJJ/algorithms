//#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
const string a = "Alice", b="Bob";

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n,k;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		if (k % 3 || n<k)
		{
			if (n % 3)
			{
				cout << a << "\n";
			}
			else
			{
				cout << b << "\n";
			}
		}
		else if (k % 3 == 0)
		{
			int r = n % (k + 1);
			if (r == k || r % 3)
			{
				cout << a << "\n";
			}
			else
			{
				cout <<b <<"\n";
			}
		}
	}
}
 
