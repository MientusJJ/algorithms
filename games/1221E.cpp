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
#include <set>
#include <map>
#include <stack>
#include <bitset>
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define Y cout << "YES" << "\n";
#define N cout << "NO" << "\n";
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxik = 2e6;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

bool solve()
{
	int a,b;
	string g;
	cin >> a >> b;
	cin >> g;
	int counter = 0;
	int twob = 0;
	bool ans = 0;
	int str=0;
	for (int i = 0; i < g.size(); i++)
	{
		if (g[i] == '.')
		{
			counter++;
		}
		if (g[i] == 'X'|| i+1==g.size())
		{
			if (counter<b)
			{
				counter = 0;
				continue;
			}
			if (counter < a) return 0;
			else if (counter < 2 * b)
			{
				ans ^= 1;
			}
			else
			{
				twob++;
				str = counter;
			}
			counter = 0;
		}
	}
	if (twob > 1)
	{
		return 0;
	}
	if (twob)
	{
		for (int i = 0; i + a <= str; i++)
		{
			int word1 = i;
			int word2 = str-i-a;
			if ((word1 >= 2 * b) || (word1 < a&&word1 >= b)|| (word2 >= 2 * b) || (word2 < a&&word2 >= b)) continue;
			if (!((ans + (word1 >= a) + (word2 >= a)) % 2))
			{
				return 1;
			}
		}
	}
	else
	{
		if (ans) return 1;
		return 0;
	}
	return 0;
}
int t;
int main()
{
	es;
	cin >> t;
	while (t--)
	{
		if (solve())
		{
			Y;
		}
		else
		{
			N;
		}
	}
	return 0;
}
