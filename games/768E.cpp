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
const int maxik = 1e2;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

map < long long, int> m[maxik];
int n, xx;
int ans;
int grundy(int x, ll mask);
int main()
{
	es;
	ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> xx;
		ans ^= grundy(xx, 0ll);
	}
	if (!ans)
	{
		Y;
	}
	else
		N;
	return 0;
}
int grundy(int x, ll mask)
{	
	if (!x)
	{
		return 0;
	}
	if (m[x].count(mask))
	{
		return m[x][mask];
	}
	set<int> s;
	for (int i = 1; i <= x; i++)
	{
		if (((mask >> i) & 1) ^ 1)
		{
			s.insert(grundy(x - i, mask | 1ll << i));
		}
	}
	m[x][mask] = 0;
	while (s.count(m[x][mask]))
	{
		m[x][mask]++;
	}
	return m[x][mask];
}
