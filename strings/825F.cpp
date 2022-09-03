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
using ull = unsigned long long;
using pii = pair<int, int>;
const int maxik = 8e3+7;
const int maxN = 1 << 18;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

int dp[maxik];
string s;
int hop[maxik];
int check(int i);
void kmp(string s);
void makeInterval();
int interval[maxik][maxik];
int main()
{
	es;
	cin >> s;
	s = " " + s;
	int n = s.size();
	for (int i=1; i<=n; i++)
	{
		dp[i] += dp[i - 1] + 2;
	}
	if (n == 2)
	{
		cout << 2 << "\n";
		return 0;
	}
	makeInterval();
	for (int i = 2; i<n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[j - 1] + interval[j][i]);
		}
	}
	cout << dp[n-1];
	return 0;
}
int check(int i)
{
	if (i <= 9) return 1;
	if (i <= 99) return  2;
	if (i <= 999) return 3;
	return 4;
}
void kmp(string s)
{
	memset(hop, 0, sizeof hop);
	int n = s.size();
	int i = 0; int j = 2;
	for (j; j <n; j++)
	{
		while (i && s[j] != s[i + 1])
		{
			i = hop[i];
		}
		if (s[j] == s[i + 1])
		{
			i++;
		}
		hop[j] = i;
	}
	return;
}
void makeInterval()
{
	for (int i = 1; i < s.size(); i++)
	{
		kmp(' ' + string(s.begin() + i, s.end()));
		for (int j = i; j < s.size(); j++)
		{
			if (j == i)
			{
				interval[i][j] = 2;
				continue;
			}
			int sizes = j + 1 - i;
			int sizesofPrefix = sizes - hop[sizes];
			interval[i][j] = sizes % sizesofPrefix == 0 ? sizesofPrefix + check(sizes / sizesofPrefix) : sizes + 1;
		}
	}
	return;
}
