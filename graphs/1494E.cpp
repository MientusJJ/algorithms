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
const int maxik = 1e5 + 7;
const int maxN = 1e1;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

int n, m;
map<pii, int> xd;
int odd, even;
int main()
{
	es;
	odd = even = 0;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		char c;
		int u, v;
		cin >> c;
		if (c == '+')
		{
			cin >> u >> v;
			char cc;
			cin >> cc;

			pii p1 = { u,v }, p2{ v,u };
			int val1 =cc-'a'+1;
			int val2 = xd[p2];
			xd[p1] = val1;
			if (val1 == val2)
			{
				even++;
				odd++;
			}
			else if (val1 != val2 && val2)
			{
				odd++;
			}
		}
		else if (c == '-')
		{
			cin >> u >> v;
			pii p1 = { u,v }, p2{ v,u };
			int val1 = xd[p1];
			int val2 = xd[p2];
			xd.erase(p1);
			if (val1 == val2)
			{
				even--;
				odd--;
			}
			else if (val1 != val2 && val2)
			{
				odd--;
			}
		}
		else
		{
			int k;
			cin >> k;
			if (((k % 2) && odd) || (k%2==0)&& even)
			{
				Y;
				continue;
			}
			N;
		}
	}
	return 0;
}
