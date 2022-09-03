#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxik = 2e5*32;
const int powik = 30;
using ll = long long;
int trie[maxik + 7][2];
int tCounter[maxik + 7][2];
void cinek(char &c, int &i);
void add(int i);
void del(int i);
void query(int i);
int cnt = 1;
int n, num;
char c;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cinek(c, num);
	}
	return 0;
}
void cinek(char &c, int &num)
{
	cin >> c >> num;
	if (c == '+')
	{
		add(num);
	}
	else if (c == '-')
	{
		del(num);
	}
	else
	{
		query(num);
	}
	return;
}
void add(int num)
{
	int tVex = 1;
	for (int i = powik; i >= 0; i--)
	{
		bool p = num & (1 << i);
		if (!(trie[tVex][p]))
		{
			trie[tVex][p] = ++cnt;
		}
		tCounter[tVex][p]++;
		tVex = trie[tVex][p];
	}

	return;
}
void del(int num)
{
	int tVex = 1;
	int tt = 0;
	for (int i = powik; i >= 0; i--)
	{
		bool p = num & (1 << i);
		tt = trie[tVex][p];
		tCounter[tVex][p]--;
		if (!(tCounter[tVex][p]))
		{
			trie[tVex][p] = 0;
		}
		tVex = tt;
	}
	return;
}
void query(int num)
{
	int res = 0;
	int tVex = 1;
	//cout << "ODP: ";
	if (!(trie[tVex][1] || trie[tVex][0]))
	{
		cout << num << "\n";
		return;
	}
	for (int i = powik; i >= 0; i--)
	{
		bool p = num & (1 << i);
		if (trie[tVex][!p])
		{
			res += (1 << i);
			tVex = trie[tVex][!p];
			continue;
		}
		tVex = trie[tVex][p];
	}
	cout << max(num, res) << "\n";
	return;
}
