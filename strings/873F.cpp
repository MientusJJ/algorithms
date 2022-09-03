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
const int maxik = 2e5 + 7;
const int maxN = 2e6 + 7;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
struct ToSort
{
	int lI, rI, indx;
	ToSort(int a, int b, int c)
	{
		lI = a;
		rI = b;
		indx = c;
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

int SA[maxik];
int ranik[maxik];
int LCP[maxik];
int r[maxik], l[maxik];
int prefs[maxik];
vector<ToSort> v;
string str = "ccababa";
bool forbid[maxik];
void make_SA();
void make_LCP();
int n, m;
stack<int> sheep;
ll ans = 0;
int main()
{
	cin >> m;
	cin >> str;
	reverse(str.begin(), str.end());
	str = ' ' + str;
	n = str.size();
	for (int i = 1; i < n; i++)
	{
		char a;
		cin >> a;
		a -= '0';
		forbid[i] = a;
		ranik[i] = str[i] - 'a' + 1;
	}
	reverse(forbid + 1, forbid + n);
	make_SA();
	make_LCP();
	for (int i = 1; i < n; i++)
	{
		prefs[i] += prefs[i - 1];
		if (forbid[SA[i]])
		{
			prefs[i]++;
		}
	}
	for (int i = 1; i < n; i++)
	{
		while (!sheep.empty() && LCP[sheep.top()] > LCP[i])
		{
			r[sheep.top()] = i;
			sheep.pop();
		}
		sheep.push(i);
	}
	while (!sheep.empty())
	{
		r[sheep.top()] = n;
		sheep.pop();
	}
	for (int i = n - 1; i > 0; i--)
	{
		while (!sheep.empty() && LCP[sheep.top()] > LCP[i])
		{
			l[sheep.top()] = i;
			sheep.pop();
		}
		sheep.push(i);
	}
	while (!sheep.empty())
	{
		l[sheep.top()] = 0;
		sheep.pop();
	}
	for (int i = 1; i < n; i++)
	{
		if (!forbid[i])
		{
			ans = n - i;
			break;
		}
	}
	for (int i = 1; i < n; i++)
	{
		int p = r[i] - l[i];
		int b = l[i] - 1;
		if (b < 0)b = 0;
		int a = prefs[r[i] - 1] - prefs[b];
		p -= a;
		ans = max(ans, 1ll * p*LCP[i]);
	}
	cout << ans;
	return 0;
}
void make_SA()
{
	bool t = 1;
	for (int k = 1; t; k *= 2)
	{
		if (n - 1 <= k) t = !t;
		v.clear();
		for (int i = 1; i < n; i++)
		{
			if (i + k < n)
			{
				v.push_back(ToSort(ranik[i], ranik[i + k], i));
				continue;
			}
			v.push_back(ToSort(ranik[i], -1, i));
		}
		sort(all(v));
		int cnt = 0;
		ranik[v[0].indx] = ++cnt;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].lI != v[i - 1].lI || v[i].rI != v[i - 1].rI)
			{
				++cnt;
			}
			ranik[v[i].indx] = cnt;
		}
	}
	for (int i = 1; i < n; i++)
	{
		SA[ranik[i]] = i;
	}
	return;

}
void make_LCP()
{
	int u = 0;
	for (int i = 1; i < n; i++)
	{
		if (ranik[i] == 1)
		{
			LCP[1] = 0;
		}
		else
		{
			int j = SA[ranik[i] - 1];
			u = max(0, u - 1);
			while (i + u < n && j + u < n && str[i + u] == str[u + j])
			{
				u++;
			}
			LCP[ranik[i]] = u;
		}
	}
	return;
}
