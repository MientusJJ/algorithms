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
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 2010;
const int maxN = 2010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
int dp[maxik][maxN][tight];
int m, d_magic;
string a, b;
int solve(string s);
bool isMagic(string s);
int main()
{
	cin >> m >> d_magic;
	cin >> a >> b;
	ll r = solve(a);
	memset(dp, 0, sizeof dp);
	ll t = solve(b);
	bool check = isMagic(a);
	t += modik;
	t += check;
	t -= r;
	t %= modik;
	cout << t;
	return 0;
}
 int solve(string s)
{
	dp[0][0][0] =dp[0][0][1] = 1;
	int p = 1;
	reverse(s.begin(), s.end());
	s = " " + s;
	
	int len = s.size();
	for (int i = 1; i < len; i++)
	{
		if (i >= 2)
		{
			p = (p * 10) % m;
		}
		for (int k = 0; k < tight; k++)
		{
			int digits = (k) ? s[i] - '0' : 9;
			for (int j = 0; j < m; j++)
			{
				for (int dig = 0; dig <= digits; dig++)
				{
					if (!((len - i) & 1) && dig != d_magic) continue;
					if (((len - i) & 1) && dig == d_magic) continue;
					int whichK = int(k && dig == digits);
					int whichJ = (dig*p + j) % m;
					dp[i][whichJ][k] += dp[i - 1][j][whichK];
					dp[i][whichJ][k] %= modik;
				}
			}
		}
	}
	return dp[len-1][0][1];
}
 bool isMagic(string s)
 {
	 int sum = 0;
	 for (int i = 0; i < s.size(); i++)
	 {
		 int dig = s[i] - '0';
		 if ((i & 1) && dig != d_magic)
		 {
			 return false;
		 }
		 if (!(i & 1) && dig == d_magic)
		 {
			 return false;
		 }
		 sum = (sum * 10 + dig) % m;
	 }
	 return sum == 0;
 }
