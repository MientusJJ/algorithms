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
const int maxik = 1e3+7;
const int maxN = 1 << 20;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;


int n, m, x, y;
long double dp[maxik][maxik];
long double matrix[maxik][maxik];
long double rowik[maxik];
int res = 0;
void anotherLevel(int row);
int main()
{
	es;
	//TXT;
	prec(10);
	cin >> n >> m >> x >> y;
	if (m == 1)
	{
		cout << double(n - x) * 2;
		return 0;
	}
	for (int i = n - 1; i >= x; i--)
	{
		anotherLevel(i);
	}
	cout << dp[x][y];
	return 0;
}
void anotherLevel(int row)
{
	for (int i = 1; i <= m; i++)
	{
		if (i == 1 || i==m)
		{
			rowik[i] = (dp[row + 1][i] / 3) + 1;
			continue;
		}
		rowik[i]= (dp[row + 1][i] / 4) + 1;
	}
	for (int i = 1; i <= m; i++)
	{
		if (i == 1)
		{
			matrix[i][1] = 2.0 / 3.;
			matrix[i][2] = -1. / 3;
		}
		else if (i == m)
		{
			matrix[i][m - 1] = -1.0 / 3.;
			matrix[i][m] = 2. / 3;
		}
		else 
		{
			matrix[i][i] = 3.0 / 4.;
			matrix[i][i + 1] = -1. / 4;
			matrix[i][i - 1] = -1. / 4;
		}
		
	}
	for (int i = 1; i <= m; i++)
	{
		double k = matrix[i + 1][i] / matrix[i][i];
		matrix[i + 1][i] = 0;
		matrix[i + 1][i + 1] -= k * matrix[i][i+1];
		rowik[i+1] -= rowik[i] * k;

	}
	for (int i = m; i; i--)
	{
		double k = matrix[i - 1][i] / matrix[i][i];
		matrix[i - 1][i] = 0;
		rowik[i-1] -= rowik[i] * k;
	}
	for (int i = 1; i <= m; i++)
	{
		dp[row][i] = rowik[i] / matrix[i][i];
	}
	return;
}
