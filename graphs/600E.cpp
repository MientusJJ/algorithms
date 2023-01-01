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
const int maxik = 1e5 + 7;
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
vector <vector<int>> g;
ll sizes[maxik], biggest[maxik],res[maxik],c[maxik],frq[maxik];
ll sum, maxcnt;
int n;
void dfs(int v=1, int par=0);
void solve(int v = 1, int par = 0, bool big=false);
void make(int v, int par, int big,int num);
int main()
{
	cin >> n;
	g.resize(n + 1);
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	for(int i=1;i<n;i++)
	{
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs();
	solve();
	for(int i=1;i<=n;i++)
	{
		cout << res[i] << " ";
	}
}
void dfs(int v,int par)
{
	sizes[v] = 1;
	for(int u:g[v])
	{
		if(u!=par)
		{
			dfs(u, v);
			sizes[v] += sizes[u];
			if(sizes[biggest[v]]<sizes[u])
			{
				biggest[v] = u;
			}
		}
	}
	return;
}
void solve(int v, int par, bool big)
{
	for(int u:g[v])
	{
		if(u!=biggest[v] && u!=par)
		{
			solve(u, v, false);
		}
	}
	if (biggest[v])
	{
		solve(biggest[v], v, true);
	}
	make(v, par, biggest[v],1);
	res[v] = sum;
	if(!big)
	{
		maxcnt = sum = 0;
		make(v, par, biggest[v], -1);
	}
}
void make(int v, int par, int big, int num)
{
	frq[c[v]] += num;
	if (num == 1)
	{
		if (maxcnt == frq[c[v]])
		{
			sum += c[v];
		}
		else if (frq[c[v]] > maxcnt)
		{
			maxcnt = frq[c[v]];
			sum = c[v];
		}

	}
	for (int u : g[v])
	{
		if (u != par && (u != big || num==-1))
		{
			make(u, v, big, num);
		}
	}
}
