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
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
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
const int maxN = 5e2;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;

int n, m, k;
int cnt = 0;
map<long long, int> col, row;
struct Line
{
	int l, r;
	Line(int ll, int rr) : l(ll), r(rr) {}
	bool operator<(Line li)
	{
		if (this->l != li.l)
		{
			return this->l < li.l;
		}
		return this->r < li.r;
	}
};
vector<Line> one[maxik],cut[maxik];
int used[maxik];
int main()
{
	es;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int x1, y2, x2, y1;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
		{
			if (y1 > y2)
			{
				swap(y1, y2);
			}
			if (col.find(x1) == col.end())
			{
				col[x1] = cnt++;
			}
			one[col[x1]].push_back(Line(y1, y2));
		}
		else
		{
			if (x1 > x2)
			{
				swap(x1, x2);
			}
			if (row.find(y1) == row.end())
			{
				row[y1] = cnt++;
			}
			one[row[y1]].push_back(Line(x1, x2));
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		sort(all(one[i]));
		int l = one[i][0].l;
		int r = one[i][0].r;
		for (int j = 1; j < one[i].size(); j++)
		{
			if (one[i][j].l > r)
			{
				cut[i].push_back(Line(l, r));
				used[i] += r - l;
				l = one[i][j].l;
				r = one[i][j].r;
			}
			else
			{
				r = max(r, one[i][j].r);
			}
		}
		cut[i].push_back(Line(l, r));
		used[i] += r - l;
	}
	int ans = 0;
	int c = n - col.size() - 1;
	int r = m - row.size() - 1;
	if (c & 1) ans ^= m;
	if (r & 1) ans ^= n;
	for (auto it = col.begin(); it != col.end(); it++)
	{
		ans ^= m - used[it->second];
	}
	for (auto it = row.begin(); it != row.end(); it++)
	{
		ans ^= n - used[it->second];
	}
	if (!ans)
	{
		cout << "SECOND\n";
	}
	else
	{
		cout << "FIRST\n";
		for (int i = 1; i < n; i++)
		{
			if (col.find(i) == col.end())
			{
				if (m >= (m^ans))
				{
					int t = m - (m^ans);
					cout << i << " 0 " << i << " " << t << "\n";
					return 0;
				}
				else
				{
					break;
				}
			}
		}
		for (int i = 1; i < m; i++)
		{
			if (row.find(i) == row.end())
			{
				if (n >= (n^ans))
				{
					int t = n - (n^ans);
					cout << "0 " << i << " " << t << " " << i << "\n";
					return 0;
				}
				else
				{
					break;
				}
			}
		}
		for (auto it = col.begin(); it != col.end(); it++)
		{
			int indx = it->second;
			int blocks = m - used[indx];
			if (blocks >= (blocks ^ ans))
			{
				cut[indx].push_back(Line(m, m));
				blocks -= blocks ^ ans;
				int sum = 0, prev = 0;
				for (int i = 0; i < cut[indx].size(); i++)
				{
					if (sum + cut[indx][i].l - prev >= blocks)
					{
						cout << it->first << " 0 " << it->first << " " << prev + blocks - sum << "\n";
						break;
					}
					sum += cut[indx][i].l - prev;
					prev = cut[indx][i].r;
				}
				return 0;
			}
		}
		for (auto it = row.begin(); it != row.end(); it++)
		{
			int indx = it->second;
			int blocks = n - used[indx];
			if (blocks >= (blocks ^ ans))
			{
				cut[indx].push_back(Line(n, n));
				blocks -= blocks ^ ans;
				int sum = 0, prev = 0;
				for (int i = 0; i < cut[indx].size(); i++)
				{
					if (sum + cut[indx][i].l - prev >= blocks)
					{
						cout << "0 " << it->first << " " << prev + blocks - sum << " " << it->first << "\n";
						break;
					}
					sum += cut[indx][i].l - prev;
					prev = cut[indx][i].r;
				}
				return 0;
			}
		}
	}
	return 0;
}
