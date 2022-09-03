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
const int maxik = 4e4 + 7;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;


int t;
int n, m;
int ans = 0;
char c;
int main()
{
	es;
	cin >> t;
	vector<set<int>> ss;
	while (t--)
	{
		ss.clear();
		ans = 0;
		cin >> n >> m;
		ss.resize(n + m + 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> c;
				if (c == '1')
				{
					ss[i + j].insert(i);
				}
			}
		}
		for (int i = 1; i < m + n; i++)
		{
			if (ss[i + 1].empty()) continue;
			ans++;
			int w = i;
			for (int j = 1; j <= n; j++)
			{
				if (j + w > ss.size() - 1)break;
				ss[w + j].erase(j);
				if (ss[w + j].size() && *ss[w+j].rbegin()>j)
				{
					w--;
				}
				else
				{
					w++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
