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
const int maxik = 5e5 + 7;
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
#ifdef DEBUG
fstream in("C:/Temp/input.txt", ios::in);
fstream out("C:/Temp/output.txt", ios::out | ios::trunc);
#define cin in
#define cout out
#endif // DEBUG 

vector < vector<int>> g;
vector<int> depth;
vector<vector<int>> anc;
int n;
int sz;
int res = 2, nodes = 5,lN=2,rN=3;
void dfs(int v = 1, int par = 0, int h = 0);
void makeLCA();
int lca(int v,int u);
int main()
{
	es;
	cin >> n;
	sz = 5 + n * 2;
	g.resize(sz);
	depth.resize(sz, 0);
	anc.resize(sz, vector<int>(maxN+1, 0));
	for (int i = 2; i < 5; i++)
	{
		g[1].push_back(i);
		g[i].push_back(1);
	}
	int u = 4;
	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		g[v].push_back(u + 1);
		g[v].push_back(u + 2);
		g[u + 1].push_back(v);
		g[u + 2].push_back(v);
		u += 2;
	}
	dfs();
	makeLCA();
	while (n--)
	{
		int de1 = depth[nodes] + depth[lN] - 2 * lca(lN, nodes);
		int de2= depth[nodes] + depth[rN] - 2 * lca(rN, nodes);
		if (de1 > res && de1 > de2)
		{
			res = de1;
			rN = nodes;
		}
		else if (de2 > res)
		{
			res = de2;
			lN = nodes;
		}
		cout << res << "\n";
		nodes += 2;
	}
	return 0;
}
void dfs(int v , int par , int h)
{
	depth[v] = h;
	anc[v][0] = (v != 1 ? par : 1);
	for (int i : g[v])
	{
		if (i != par)
		{
			dfs(i, v, h + 1);
		}
	}
	return;
}
void makeLCA()
{
	for (int k = 1; k <= maxN; k++)
	{
		for (int v = 1; v < sz; v++)
		{
			anc[v][k] = anc[anc[v][k-1]][k-1];
		}
	}

}
int lca(int v, int u)
{
	if (depth[v] < depth[u])
	{
		swap(v, u);
	}
	for (int k = 20; k + 1; k--)
	{
		if (depth[anc[v][k]] >= depth[u])
		{
			v = anc[v][k];
		}
	}
	if (v == u)
	{
		return depth[v];
	}
	for (int k = 20; k + 1; k--)
	{
		if (anc[v][k]!=anc[u][k])
		{
			v = anc[v][k];
			u = anc[u][k];
		}
	}
	return depth[anc[v][0]];

}
