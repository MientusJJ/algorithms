//#include "pch.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> es;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int pair = 0;
	string word;
	cin >> n >> m;
	int t = n + m;
	for (int i = 0; i < t; i++)
	{
		cin >> word;
		if (es[word] == 1)
		{
			pair++;
		}
		es[word]++;
	}
	if (n > m)
	{
		cout << "YES";
	}
	else if(n<m)
	{
		cout << "NO";
	}
	else
	{
		if (pair % 2)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}
}
 
