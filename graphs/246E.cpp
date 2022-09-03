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
const int maxik = 5e5 + 7;
//const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;

int n,m;
vector<pair<string, int>> family;
vector<vector<pii>> q;
vector<vector<int>> g;
vector<int> names;
vector<int> height;
vector<int> child;
vector<int> ans;
vector<map<int, int>> mp;
void add(int v, int val);
void dfs(int v);
void dfs2(int v,bool a);
vector<bool> biggest;
int main()
{
	es;
	//txt;
	cin >> n;
	names.resize(n + 1);
	g.resize(n + 1);
	height.resize(n + 1, 0);
	q.resize(n + 1);
	child.resize(n + 1);
	mp.resize(n + 1);
	biggest.resize(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		string s;
		int anc;
		cin >> s >> anc;
		family.push_back({ s,i });
		if (anc)
		{
			g[anc].push_back(i);
		}
		else
		{
			height[i] = 1;
		}
	}
	sort(all(family));
	names[family[0].second] = 1;
	for (int i = 1; i <family.size(); i++)
	{
		if (family[i].first == family[i - 1].first)
		{
			names[family[i].second] = names[family[i - 1].second];
		}
		else
		{
			names[family[i].second] = names[family[i - 1].second]+1;
		}
	}
	cin >> m;
	ans.resize(m + 1);
	for (int i = 1; i <= m; i++)
	{
		int v, k;
		cin >> v >> k;
		q[v].push_back({ k,i });
	}
	for (int i = 1; i <= n; i++)
	{
		if (height[i]==1)
		{
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (height[i] == 1)
		{
			dfs2(i,0);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
void dfs(int v)
{
	child[v] = 1;
	for (int i:g[v])
	{
		height[i] = height[v] + 1;
		dfs(i);
		child[v] += child[i];
	}
	return;
}
void dfs2(int v, bool b)
{
	int BigD = -1,mx=-1;
	for(int u:g[v])
	{
		if (child[u] > mx)
		{
			BigD = u;
			mx = child[u];
		}
	}
	for (int u : g[v])
	{
		if (BigD != u)
		{
			dfs2(u, 0);
		}
	}
	if (BigD != -1)
	{
		dfs2(BigD, 1);
		biggest[BigD] = 1;
	}
	add(v, 1);
	for (auto p : q[v])
	{
		int h = height[v] + p.first;
		if (h <= n)
		{
			ans[p.second] = mp[h].size();
		}
	}
	if (BigD != -1)
	{
		biggest[BigD] = 0;
	}
	if (!b)
	{
		add(v, -1);
	}
	return;
}
void add(int v, int val)
{
	mp[height[v]][names[v]] += val;
	if (!mp[height[v]][names[v]])
	{
		mp[height[v]].erase(names[v]);
	}
	for (int u : g[v])
	{
		if(!biggest[u])
		add(u, val);
	}
	return;
}
