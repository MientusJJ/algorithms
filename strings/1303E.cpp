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
#include<set>
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
const int maxik = 4e2+7;
const int maxN = 30;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

struct change 
{
	string b;
	string p;
	int counter;
	change()
	{
		b = p="";
		counter = 0;
	}
	change(string bb, string pp, int i)
	{
		this->b = bb;
		this->p = pp;
		this->counter = i;
	}
};
int n;
int hop[maxik][maxN];
int dp[maxik][maxik];
void gethop(string);
bool check(string, string,int);
int main()
{
	es;
	cin >> n;
	
	while (n--)
	{
		string s,t;
		bool good = false;
		cin >> s >> t;
		gethop(s);
		for (int i = 0; i <= t.size(); i++)
		{
			if (check(t.substr(0, i), t.substr(i),s.size()))
			{
				good = 1;
				break;
			}
		}
		if (good)
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
void gethop(string s)
{
	memset(hop, INF, sizeof hop);
	for (int i = s.size()-1; i + 1; i--)
	{
		for (int j = 0; j < maxN; j++)
		{
			hop[i][j] = hop[i + 1][j];
		}
		hop[i][s[i] - 'a'] = i;
	}
	return;
}
bool check(string a, string b, int n)
{
	int alen = a.size();
	int blen = b.size();
	memset(dp, INF, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i <= alen; i++)
	{
		for (int j = 0; j <= blen; j++)
		{
			int indx = dp[i][j];
			if (indx >= n)
			{
				continue;
			}
			if (i+1<=alen)
			{
				dp[i + 1][j] = min(dp[i + 1][j], hop[indx][a[i] - 'a'] + 1);
			}
			if (j+1<=blen)
			{
				dp[i][j+1] = min(dp[i ][j+1], hop[indx][b[j] - 'a'] + 1);
			}
		}
	}
	return dp[alen][blen]<=n;
}
