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
const int maxik = 1e4 + 7;
const int maxN = 2e6 + 7;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
struct ToSort
{
	int lI, rI, indx, word;
	ToSort(int a, int b, int c, int d)
	{
		lI = a;
		rI = b;
		indx = c;
		word = d;
	}
	ToSort()
	{
		lI = rI = indx = 0;
	}
	bool operator<(const ToSort &a)
	{
		if (this->lI != a.lI)
		{
			return this->lI < a.lI;
		}
		return this->rI < a.rI;
	}
};

int ans = INF;
int n, m, maxek, len, cnt,u=0;
string s1, s2, s;
int ranik[maxik], SA[maxik], ind[maxik];
void make_SA();
void make_LCP();
int LCP[maxik];
int main()
{
	es;
	cin >> s1;
	cin >> s2;
	n = s1.size();
	m = s2.size();
	s = s1 + ' ' + s2;
	len = s.size();
	for (int i = 0; i < s.size(); i++)
	{
		ranik[i] = s[i] - 'a' + 1;
	}
	make_SA();
	make_LCP();
	for (int i = 1; i < len; i++)
	{
		if (ind[i - 1] == ind[i]) continue;
		int pre = LCP[i - 1];
		int nxt = LCP[i + 1];
		if (LCP[i] > max(pre, nxt))
		{
			ans = min(ans, max(pre, nxt) + 1);
		}
	}
	if (ans == INF)
	{
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
void make_SA()
{
	vector<ToSort> v(len);
	bool  t = 1;
	for (int k = 1; t; k *= 2)
	{
		if (k >= len) t = !t;
		for (int i = 0; i < len; i++)
		{
			if (i + k < len)
			{
				v[i] = ToSort(ranik[i], ranik[i + k], i, 2);
			}
			else
			{
				v[i] = ToSort(ranik[i], -INF, i, 2);
			}
			v[i].word = i <= n ? 1 : 2;
		}
		sort(v.begin(),v.end());
		cnt = 0;
		ranik[v[0].indx] = cnt;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].lI != v[i - 1].lI || v[i].rI != v[i - 1].rI || (v[i].word != v[i - 1].word && !t))
			{
				++cnt;
			}
			ranik[v[i].indx] = cnt;
		}

	}
	for (int i = 0; i < len; i++)
	{
		SA[ranik[i]] = i;
		ind[ranik[i]] = i <= n ? 1 : 2;
	}
	return;
}
void make_LCP()
{
	for (int i = 0; i < len; i++)
	{
		if (ranik[i] == 0)
		{
			continue;
		}
		else
		{
			if (u) u--;
			int j = SA[ranik[i] - 1];
			while (i + u < len && j + u < len && s[i + u] == s[j + u])
			{
				++u;
			}
			LCP[ranik[i]] = u;
		}
	}
	return;
}
