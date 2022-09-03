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
const int maxN = 1<<20;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
int cookiesTree[maxN << 1];
ll sumTree[maxN << 1];
struct vertex
{
	int numofCookies=0;
	int timetoEat=0;
};
void upd(int num, ll t, int indx, int l , int r);
int query(ll t, int indx, int l, int r);
void dfs(int v, ll t);
vector<vector<pair<int,int>>> g;
vector<vertex> cookies;
int n;
int sons[maxik];
int dp[maxik];
ll timer;

int main()
{
	es;
	cin >> n >> timer;
	g.resize(n + 1);
	cookies.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> cookies[i].numofCookies;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> cookies[i].timetoEat;
	}
	for (int i = 2; i <=n; i++)
	{
		int v, times;
		cin >> v >> times;
		times *= 2;
		g[v].push_back(make_pair(i, times));
	}
	dfs(1, timer);
	cout << dp[1];
	return 0;
}
void upd(int num, ll t, int indx = 1, int l = 1, int r = maxN)
{
	sumTree[indx] += 1ll * num * t;
	cookiesTree[indx] += num;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (t <= mid)
	{
		upd(num, t, indx * 2, l, mid);
	}
	else
	{
		upd(num, t, indx * 2 + 1, mid + 1, r);
	}
	return;
}
int query(ll t, int indx = 1, int l = 1, int r = maxN)
{
	if (sumTree[indx] <= t)
	{
		return cookiesTree[indx];
	}
	if (l == r)
	{
		return t / l;
	}
	int mid = (l + r) >> 1;
	if (t >= sumTree[indx * 2])
	{
		return cookiesTree[indx * 2] + query(t - sumTree[indx * 2], indx * 2 + 1, mid + 1, r);
	}
	return query(t, indx * 2, l, mid);
}
void dfs(int v, ll t)
{
	if (t <= 0)
	{
		return;
	}
	upd(cookies[v].numofCookies, cookies[v].timetoEat);
	dp[v] = query(t);
	int one=0, two=0;
	for (pair<int, int> u : g[v])
	{
		dfs(u.first, t - u.second);
		if (dp[u.first] > one)
		{
			two = one;
			one = dp[u.first];
		}
		else if(dp[u.first]>two)
		{
			two = dp[u.first];
		}
	}
	if (v == 1)
	{
		dp[v] = max(dp[v], one);
	}
	else
	{
		dp[v] = max(dp[v], two);
	}
	upd(-cookies[v].numofCookies, cookies[v].timetoEat);
	return;
}
