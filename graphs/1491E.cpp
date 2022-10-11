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
const int maxik = 2e5+1;
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

vector<ll> f(maxN + 1, 0);
int n,hm=0;
vector<vector<pii>> g;
vector<int> depth;
vector<bool> vis;
int indx, bU, bV,branch;
bool check(int v, int hmm);
void dfs(int v, int par, int hmm);
int main()
{
	es;
	cin >> n;
	if (n == 1)
	{
		cout << "YES" << endl;
		return 0;
	}
	g.resize(n + 1);
	vis.resize(n + 1, false);
	depth.resize(n + 1,0);
	for (int i = 1; i < n; i++)
	{
		int v, u;
		cin >> v >> u;
		g[v].push_back({ u,i });
		g[u].push_back({ v,i });
	}
	f[1] = 1;
	f[0] = 1;
	for (size_t i=2;i<=maxN;i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	while (f[hm+1]<=n)
	{
		hm++;
	}
	if (n != f[hm])
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << (check(1, hm) ? "YES" : "NO") << endl;
	return 0;
}
bool check(int v, int hmm)
{
	if (hmm <= 1)
	{
		return 1;
	}
	bU = bV = indx = -1;
	dfs(v, -1, hmm);
	if (bV == -1)
	{
		return 0;
	}
	vis[indx] = 1;
	int vv = bV, uu = bU, in = branch;
	return check(uu, in) && check(vv, in == hmm - 1 ? hmm - 2: hmm - 1);
}
void dfs(int v,int par, int hmm)
{
	depth[v] = 1;
	for (auto[u, ind] : g[v])
	{
		if (u == par || vis[ind])
		{
			continue;
		}
		dfs(u, v, hmm);
		if (~bV)
		{
			break;
		}
		if (depth[u] == f[hmm - 1] || depth[u] == f[hmm - 2])
		{
			indx = ind;
			bV = v;
			bU = u;
			branch = (depth[u] == f[hmm - 1] ? hmm - 1 : hmm - 2);
			break;
		}
		depth[v] += depth[u];
	}
}

