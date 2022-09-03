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
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 1e5 + 7;
const int maxN = 1 << 14;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

struct horizline
{
	int x1, x2, y;
	horizline()
	{
		x1 = x2 = y = 0;
	}
	horizline(int xx1, int xx2, int yy)
	{
		x1 = xx1;
		x2 = xx2;
		y = yy;
	}
};
struct verticalline
{
	int x, y1, y2;
	verticalline()
	{
		x = y1 = y2 = 0;
	}
	verticalline(int xx, int yy1, int yy2)
	{
		x = xx;
		y1 = yy1;
		y2 = yy2;
	}
};
bool Horizontalcomp(const horizline &b, const horizline &c)
{
	if (b.y != c.y) return b.y < c.y;
	return b.x1 < c.x2;
}
bool Verticalcomp(const verticalline &b, const verticalline &c)
{
	
	return b.y2 < c.y2;
}
void upd(int x, int value);
void swapik(int & a, int &b);
vector<verticalline> v;
vector<horizline> h;
deque<pii> borders;
int sTree[maxN*2];
int find(int l, int r, int L=1, int R=maxN, int indx=1);

ll ans = 0;
int n,x1,x2,y3,y2;
int main()
{
	es;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x1 >> y3 >> x2 >> y2;
		y3 += 5001;
		y2 += 5001;
		x1 += 5001;
		x2 += 5001;
		if (x1 == x2)
		{
			if (y2 < y3) swapik(y2, y3);
			verticalline p(x1, y3, y2);
			v.push_back(p);
			
		}
		else
		{
			if (x2 <x1) swapik(x2, x1);
			horizline p(x1, x2, y3);
			h.push_back(p);
		}
	}
	if (v.size() < 2 || h.size() < 2) 
	{
		cout << ans << "\n";
		return 0;
	}
	sort(all(h), Horizontalcomp);
	sort(all(v), Verticalcomp);
	for (int i = 0; i < h.size(); i++)
	{
		borders.clear();
		memset(sTree, 0, sizeof sTree);
		for (int j = 0; j < v.size(); j++)
		{
			if (h[i].x1 <= v[j].x &&h[i].x2 >= v[j].x && h[i].y >= v[j].y1 &&h[i].y <= v[j].y2)
			{
				borders.push_back(make_pair(v[j].x, v[j].y2));
				upd(v[j].x, 1);
			}
		}
		for (int ii = i + 1; ii < h.size(); ii++)
		{
			while (!borders.empty() && borders.front().second<h[ii].y)
			{
				upd(borders.front().first, -1);
				borders.pop_front();
			}
			int tmp = find(h[ii].x1, h[ii].x2);
			ans += ((tmp - 1)*tmp) / 2;
		}
	}
	cout << ans << "\n";
	return 0;
}
void swapik(int & a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}
void upd(int x, int value)
{
	int xx = -1 + x + maxN;
	while (xx)
	{
		sTree[xx] += value;
		xx /= 2;
	}
	return;
}
int find(int l, int r, int L, int R, int indx)
{
	if (R < L || R<l || L > r)
	{
		return 0;
	}
	if (R <= r && L >= l)
	{
		return sTree[indx];
	}
	int mid = (L + R) >> 1;
	return find(l, r, L, mid, indx * 2) + find(l, r, mid + 1, R, indx * 2 + 1);
}
