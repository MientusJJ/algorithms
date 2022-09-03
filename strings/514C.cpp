#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <string>
#include <cmath>
#include <math.h>
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 1e6 + 7;
const int maxN = 1 << 14;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 3;

int trie[maxik][tight];
bool isEnd[maxik][tight];
void insTree(const  string &);
bool ans(const string &s, int indx = 0, bool flag = 0,int root=0);
int counter;
int n, m;
int main()
{
	es;
	counter = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		insTree(s);
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (ans(s))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}
void insTree(const  string &s )
{
	int root = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (!trie[root][s[i] - 'a'])
		{
			trie[root][s[i] - 'a'] = ++counter;
		}
		if (i + 1 == s.size())
		{
			isEnd[root][s[i] - 'a'] = 1;
		}
		root = trie[root][s[i] - 'a'];
		
	}
	return;
}
bool ans(const string &s, int indx , bool flag, int root)
{
	if (indx >= (int)s.size())
	{
		return false;
	}
	int letter = s[indx] - 'a';
	bool result=false;
	for (int i = 0; i < 3; i++)
	{
		if (flag && letter != i || !trie[root][i])
		{
			continue;
		}
		if (i == letter)
		{
			if (flag && indx + 1 == s.size() && isEnd[root][i])
			{
				return true;
			}
			result = result | ans(s, indx + 1, flag, trie[root][i]);
		}
		else
		{
			if (!flag && indx + 1 == s.size() && isEnd[root][i])
			{
				return true;
			}
			result= result | ans(s, indx + 1, 1, trie[root][i]);
		}
		
	}
	return result;
}
