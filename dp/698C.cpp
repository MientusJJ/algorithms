#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <fstream>
#include <chrono>
#include <random>
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
//#define TXTcreate freopen("C:/Temp/output.txt","w",stdout);freopen("input.txt","w",stdout);
#define TXT  freopen("C:/Temp/input.txt","r",stdin); freopen("C:/Temp/output.txt","w",stdout);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define randomizer mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 30;
const int maxN = 1 <<20;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;

vector<double> p,res;
int n,k;
int cnt = 0;
double dp[maxN + 7];
bitset<maxik> files;
int main()
{
	es;
	//TXT;
	prec(10);
	cin >> n >> k;
	memset(dp, 0, sizeof dp);
	p.resize(n,0);
	res.resize(n, 0);
	for (int i=0;i<p.size();i++)
	{
		cin >> p[i];
		if (p[i] < eps)
		{
			cnt++;
		}
	}
	k = min(k, n - cnt);
	if(n<=k)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << "1.0 ";
		}
		cout << endl;
		return 0;
	}
	dp[0] = 1;
	for (int i = 0; i < (1 << n); i++)
	{
		double pSum = 0;
		for (int j = 0; j < n; j++)
		{
			if (!(i&(1 << j)))
			{
				pSum += p[j];
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (!(i&(1 << j)))
			{
				dp[i | (1 << j)] += dp[i] * (p[j] / pSum);
			}
		}
	}
	for (int i = 0; i < (1 << n); i++)
	{
		files.set();
		files &= i;
		int in = files.count();
		if (in == k)
		{
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j))
				{
					res[j] += dp[i];
				}
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
