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
#define txt  freopen("C:/Temp/input.txt","r",stdin); freopen("C:/Temp/output.txt","w",stdout);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define randomizer mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define mst(v,k) memset((v),(k),sizeof(v)); 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 1e5 + 7;
const int maxN = 20;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;
const double PI = acos(-1.);

struct com
{
	double x, y;
	com operator + (const com &d) const {
		com cp;
		cp.x = this->x + d.x;
		cp.y = this->y + d.y;
		return cp;
	}
	com operator - (const com &d) const {
		com cp;
		cp.x = this->x - d.x;
		cp.y = this->y - d.y;
		return cp;
	}
	//com operator( const com &d) const { return (com) { xd.x, yd.y }; }
	com operator * (const com &d) const 
	{ 
		com cp;
		cp.x = x * d.x - y * d.y;
		cp.y = x * d.y + y * d.x;
		return cp;
	}
	com operator/(const double &d) const {
		com cp;
		cp.x = this->x / d;
		cp.y = this->y / d;
		return cp;
	}
	com(double xx, double yy)
	{
		this->x = xx;
		this->y = yy;
	}
	com()
	{
		x = y = 0.;
	}
};
int lg = 0,n;
string s, t;
vector<int> rev;
vector<com> a, b;
const int letters = 6;
vector<vector<int>> f;
void FFT(vector<com> &a, bool invert=0);
int findik(int x, int y);
int main()
{
	es;
	//txt;
	cin >> s >> t;
	s = " " + s;
	t = " " + t;
	while ((1 << lg) < s.size() * 2)
	{
		lg++;
	}
	n = 1 << lg;
	rev.resize(n,0);
	a.resize(n);
	b.resize(n);
	f.resize(n);
	int p = s.size() - t.size() + 1;
	for (int i = 0; i < f.size(); i++)
	{
		f[i].resize(letters);
	}
	for (int i = 1, j = 0; i < rev.size(); i++)
	{
		int b = n >> 1;
		for (; j&b; b >>= 1)
		{
			j^=b;
		}
		j ^= b;
		rev[i] = j;
	}
	for (int i = 1; i <= p; i++)
	{
		for (int j = 0; j < letters; j++)
		{
			f[i][j] = j;
		}
	}
	for (int i = 0; i < letters; i++)
	{
		for (int j = 0; j < letters; j++)
		{
			if (i == j)
			{
				continue;
			}
			for (int k = 0; k < n; k++)
			{
				a[k] = b[k] = com(0, 0);
			}
			for (int k = 1; k <= s.size(); k++)
			{
				if (s[k] - 'a' == i)
				{
					a[k] = com(1, 0);
				}
			}
			for (int k = 1; k <= t.size(); k++)
			{
				if (t[k] - 'a' == j)
				{
					b[t.size()-k+1] = com(1, 0);
				}
			}
			FFT(a, 0), FFT(b, 0);
			for (int k = 0; k < n; k++)
			{
				a[k] = a[k] * b[k];
			}
			FFT(a, 1);
			for (int k=1; k <= p;k++)
			{
				if (a[k + t.size()].x > 0.5)
				{
					int x, y;
					x = findik(k, i), y = findik(k, j);
					if (x != y)
					{
						f[k][x] = y;
					}
				}
			}
		}
	}
	for (int k = 1; k <= p; k++)
	{
		int ans = 0;
		for (int i = 0; i < letters; i++)
		{
			if (f[k][i] != i)
			{
				ans++;
			}
		}
		cout << ans << " ";
	}
	return 0;
}
void FFT(vector<com> &a, bool invert)
{
	for (int i = 0; i < n; i++)
	{
		if (rev[i] > i)
		{
			swap(a[i], a[rev[i]]);
		}
	}
	for (int l = 2; l <= n; l *= 2)
	{
		double ang = 2 * PI / l * (invert ? -1 : 1);
		com wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += l)
		{
			com w(1, 0);
			for (int j = 0; j < l / 2; j++)
			{
				com c = a[i + j];
				com d = a[i + j + l / 2] * w;
				a[i + j] = c + d;
				a[i + j + l / 2] = c - d;
				w = w*wlen;
			}
		}
	}
	if (invert)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] =a[i]/n;
		}
	}
	return;
}
int findik(int x, int y)
{
	if (f[x][y] == y)
	{
		return y;
	}
	return f[x][y] = findik(x, f[x][y]);
}
