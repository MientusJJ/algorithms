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


int main()
{
	es;
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	if (x + b >= y && x + a <= y)
	{
		cout << "FIRST\n" << y << "\n";
		return 0;
	}
	if ((x < y && b <= 0)||(x > y && b > 0))
	{
		cout << "DRAW\n";
		return 0;

	}
	if (a <= 0 && b>=0)
	{
		cout << "DRAW\n";
		return 0;
	}
	int xx = x; int yy = y; int f = 1;
	if (x > y)
	{
		a *= -1;
		b *= -1;
		f =  -1;
		x ^= y;
		y ^= x;
		x ^= y;
		a ^= b;
		b ^= a;
		a ^= b;
	}
	int dist = y - x;
	if (((dist) % (a + b)) == 0)
	{
		cout << "SECOND\n";
	}
	else if (((dist % (a + b)) >= a) && ((dist) % (a + b)) <= b)
	{
		cout << "FIRST\n";
		cout << xx + f * (dist % (a + b));
	}
	else
	{
		cout << "DRAW";
	}
	return 0;
}
