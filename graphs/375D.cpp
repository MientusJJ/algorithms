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
const int maxik = 3e5 + 7;
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
void dfs(int v = 1, int par = 0);
vector<vector<int>> g;
vector<vector<pii>> q;
vector<int> res;
int biggest[maxik],c[maxik],sizes[maxik],nodes[maxik],freq[maxik];
int n, m;
void solve(int v = 1, int par = 0, bool big=false);
void sum(int v, int par, int num, int big);
int main()
{
	es;
	cin >> n >> m;
	res.resize(m);
	q.resize(n + 1);
	g.resize(n + 1);
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	for(int i=1;i<n;i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<m;i++)
	{
		int v, k;
		cin >> v >> k;
		q[v].push_back({ i,k });
	}
	dfs();
	solve();
	for(auto p: res)
	{
		cout << p << "\n";
	}
	return 0;
}
void dfs(int v, int par)
{
	sizes[v] = 1;
	for(int u: g[v])
	{
		if(par!=u)
		{
			dfs(u, v);
			sizes[v] += sizes[u];
			if(sizes[u]>sizes[biggest[v]])
			{
				biggest[v] = u;
			}
		}
	}
}
void solve(int v, int par, bool big)
{
	for(int u: g[v])
	{
		if(u!=par && u!=biggest[v])
		{
			solve(u, v, false);
		}
	}
	if(biggest[v])
	{
		solve(biggest[v], v, true);
	}
	sum(v, par, 1, biggest[v]);
	for(auto val:q[v])
	{
		res[val.first] = nodes[val.second];
	}
	if(!big)
	{
		sum(v, par, -1, 0);
	}
}
void sum(int v,int par,int num,int big)
{
	if(num==-1)
	{
		nodes[freq[c[v]]]+=num;
	}
	freq[c[v]] += num;
	if(num==1)
	{
		nodes[freq[c[v]]] += num;
	}
	for (auto u:g[v])
	{
		if(u!=par && u!=big)
		{
			sum(u, v, num, big);
		}
	}
}
