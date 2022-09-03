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
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
#define TXTcreate freopen("output.txt","w",stdout);freopen("input.txt","w",stdout);
#define TXT  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxik = 4e1 + 7;
const int maxN = 1 << 20;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;

int n, m;
vector<ll> vers[2];
void makeSquare(int amount, int v);
inline bool check(ll x)
{
	return sqrt(x) == ll(sqrt(x));
}
int main()
{
	es;
	//TXT;
	cin >> n >> m;
	makeSquare(n, 0);
	makeSquare(m, 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << ll(sqrt(vers[0][i] * vers[1][j])) << " ";
		}
		cout << "\n";
	}
	return 0;
}
void makeSquare(int amount, int v)
{
	vers[v].resize(amount + 1, 1);
	ll sum = amount;
	if (check(sum))
	{
		return;
	}
	for (int add = 3; 1; add += 2)
	{
		for (int i = 1; i <= amount; i++)
		{
			vers[v][i] += add;
			sum += add;
			if (check(sum))
			{
				return;
			}
		}
	}
}
