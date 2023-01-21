#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//#define DEBUG


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
#include <fstream>
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
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
const int maxik = 1e6 + 7;
const int maxN = 30;
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
#ifdef DEBUG
fstream in("C:/Temp/input.txt", ios::in);
fstream out("C:/Temp/output.txt", ios::out | ios::trunc);
#define cin in
#define cout out
#endif // DEBUG 

struct edge
{
	int u = 0; int v = 0;
	int maxek = 0,minek = 0;
	edge(int uu,int vv,int ma,int mi)
	{
		u = uu;
		v = vv;
		maxek = ma;
		minek = mi;
	}
};
int findik(int x);
void unionik(int a, int b);
ll maxSum = 0, minSum = 0;
int a[maxik];
int par[maxik],sz[maxik];
vector<edge> e;
int n;
int main()
{
	es;
	cin >> n;
	e.reserve(n);
	e.emplace_back(0, 0, 0, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		e.emplace_back(u, v, max(a[u], a[v]), min(a[u], a[v]));
	}
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}
	sort(begin(e) + 1, end(e),
		[](const edge& a, const edge& b)
		{
			return a.minek > b.minek;
		}
	);
	for(int i=1;i<n;i++)
	{
		minSum += 1ll * sz[findik(e[i].v)] * sz[findik(e[i].u)] * e[i].minek;
		unionik(e[i].v, e[i].u);
	}
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}
	sort(begin(e) + 1, end(e),
		[](const edge& a, const edge& b)
		{
			return a.maxek < b.maxek;
		}
	);
	for (int i = 1; i < n; i++)
	{
		maxSum += 1ll * sz[findik(e[i].v)] * sz[findik(e[i].u)] * e[i].maxek;
		unionik(e[i].v, e[i].u);
	}
	cout << maxSum - minSum;
	return 0;
}
int findik(int x)
{
	if (x == par[x])
	{
		return x;
	}
	else return par[x] = findik(par[x]);
}
void unionik(int a, int b)
{
	 a = findik(a);
	 b = findik(b);
	if (a == b) return;
	if(sz[a]>sz[b])
	{
		swap(a, b);
	}
	par[a] = b;
	sz[b] += sz[a];
	return;
}

