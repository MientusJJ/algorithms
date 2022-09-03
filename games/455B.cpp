#include <iostream>
#include <vector>
#include <string>
#define es cin.tie(0);ios::sync_with_stdio(false);
using namespace std;
const int maxik = 1e5;
const int letters = 27;
int tab[maxik + 7][letters];
const string f = "First";
const string s = "Second";
int nL = 0;
bool DFS(int v, bool condition)
{
	bool ret = 0;
	bool Happened = 0;
	for (int i = 1; i <= 27; i++)
	{
		if (tab[v][i])
		{
			Happened = true;
			if (!(DFS(tab[v][i], condition))) ret = 1;
		}
	}
	if (condition == 0 && Happened == 0)
	{
		ret = 1;
	}
	return ret;
}
int main()
{
	es;
	int n, k;
	cin >> n >> k;
	int root = ++nL;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int t = root;
		for (int j = 0; j < s.length(); j++)
		{
			if (!tab[t][s[j] + 1 - 'a'])
			{
				tab[t][s[j] + 1 - 'a'] = ++nL;
			}
			t = tab[t][s[j] + 1 - 'a'];
		}
	}
	bool fWin = DFS(root, 1);
	bool fLose = DFS(root, 0);
	if (fWin && fLose)
	{
		cout << f << "\n";
	}
	else if (!fWin)
	{
		cout << s << "\n";
	}
	else
	{
		if (k % 2)
		{
			cout << f << "\n";
		}
		else
		{
			cout << s << "\n";
		}
	}
	//system("pause");
}
