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

struct eg
{
	ll val;
	int from;
	int to;
	eg()
	{
		from = to = val = 0;
	}
	eg(int a,int b,ll v)
	{
		from = a;
		to = b;
		val = v;
	}
};
struct Compadre
{
	bool operator()(const eg&a,const eg &b)
	{
		return a.val > b.val;
	}
};

struct Node
{
	ll val;
	int to;
	Node()
	{
		to = val = 0;
	}
	Node (int b, ll v)
	{
		to = b;
		val = v;
	}
};
struct Compadre2
{
	bool operator()(const Node &a, const Node & b)
	{
		return a.val > b.val;
	}
};
int Ancenstor[maxik][maxN];
int myset[maxik],quantity[maxik];
int n, m,q;
vector<int> toDij;
void krusk();
vector < vector<Node>> g,gTree;
vector<bool> ifDij;
vector<vector<ll>> dis;
vector<bool> visited;
vector<ll> disinTree;
vector<int> depth;
void dijk(int v);
void dfs(int v);
int LCA(int x, int y);
void madeLCA();
priority_queue<eg,vector<eg>,Compadre> e;
int main()
{
	es;
	//txt;
	cin >> n >> m;
	g.resize(n + 1);
	ifDij.resize(n + 1,false);
	gTree.resize(n + 1);
	dis.resize(n + 1);
	disinTree.resize(n + 1, 0);
	depth.resize(n + 1, 0);
	visited.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		myset[i] = i;
		quantity[i] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, val;
		cin >> u >> v >> val;
		eg a(u,v,val);
		e.push(a);
		Node c(u, val);
		Node d(v, val);
		g[u].push_back(d);
		g[v].push_back(c);
	}
	krusk();
	for (int i = 0; i < toDij.size(); i++)
	{
		dijk(toDij[i]);
	}
	fill(all(visited), 0);
	depth[1] = Ancenstor[1][0] = 1;
	dfs(1);
	madeLCA();
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		int a = LCA(x, y);
		ll val = disinTree[x] + disinTree[y] - 2 * disinTree[a];
		for (int i: toDij)
		{
			val = min(val, dis[i][x] + dis[i][y]);
		}
		cout << val << endl;
	}
	return 0;
}
int findik(int a)
{
	if (myset[a] != a)
	{
		myset[a] = findik(myset[a]);
	}
	return myset[a];
}
void unionik(int a, int b)
{
	a = findik(a);
	b = findik(b);
	if (quantity[a] < quantity[b])
	{
		swap(a,b);
	}
	quantity[a] += quantity[b];
	myset[b] = a;
	return;
}
void krusk()
{
	while (e.size())
	{
		eg a = e.top();
		e.pop();
		int u = a.to;
		int v = a.from;
		if (findik(u) != findik(v))
		{
			unionik(u, v);
			Node c(u, a.val);
			Node d(v, a.val);
			gTree[u].push_back(d);
			gTree[v].push_back(c);
		}
		else
		{
			if (!ifDij[u])
			{
				toDij.push_back(u);
				ifDij[u] = 1;
			}
			if (!ifDij[v])
			{
				toDij.push_back(v);
				ifDij[v] = 1;
			}
		}
	}
}
void dfs(int v)
{
	visited[v] = 1;
	for (auto  u : gTree[v])
	{
		if (!visited[u.to])
		{
			visited[u.to] = 1;
			disinTree[u.to] = u.val + disinTree[v];
			Ancenstor[u.to][0] = v;
			depth[u.to] = 1 + depth[v];
			dfs(u.to);
		}
	}
	return;
}
void madeLCA()
{
	for (int k = 1; k <= 18; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			Ancenstor[i][k] = Ancenstor[Ancenstor[i][k - 1]][k - 1];
		}
	}
}
void dijk(int v)
{
	dis[v].resize(n + 1,0);
	fill(all(visited), 0);
	visited[v] = 1;
	priority_queue<Node, vector<Node>, Compadre2> que;
	for (auto i : g[v])
	{
		que.push(i);
	}
	while (que.size())
	{
		auto u = que.top();
		que.pop();
		if (!visited[u.to])
		{
			visited[u.to] = 1;
			dis[v][u.to] = u.val;
			for (auto i : g[u.to])
			{
				Node d(i.to, u.val + i.val);
				que.push(d);
			}
		}
	}
	return;
}
int LCA(int x,int y)
{
	if (depth[x] < depth[y])
	{
		swap(x, y);
	}
	for (int i = 18; i >= 0; i--)
	{
		if (depth[Ancenstor[x][i]] >= depth[y])
		{
			x = Ancenstor[x][i];
		}
	}
	if (x == y)
	{
		return x;
	}
	for (int i = 18; i >= 0; i--)
	{
		if (Ancenstor[x][i] != Ancenstor[y][i])
		{
			x = Ancenstor[x][i];
			y = Ancenstor[y][i];
		}
	}
	return Ancenstor[x][0];
}
