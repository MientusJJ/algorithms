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
vector<int> roots,ranik;
vector <set<int>> setik;
vector <vector<int>> dp;
int t, n;
void dfs(int v);
ll ans = 0;

int main()
{
	es;
	cin >> t;
	while(t--)
	{
		cin >> n;
		g.clear();
		ans = 0;
		roots.clear();
		ranik.clear();
		setik.clear();
		dp.clear();
		dp.resize(n + 1);
		setik.resize(n + 1);
		g.resize(n + 1);
		ranik.resize(n + 1,INF);
		for (int i=1;i<=n;i++)
		{
			int v;
			cin >> v;
			if(v)
			{
				g[v].push_back(i);
			}
			else
			{
				roots.push_back(i);
			}
		}
		for(auto v:roots)
		{
			dfs(v);
			ans ^= dp[v].back();
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
void dfs(int v)
{
	for(auto u:g[v])
	{
		dfs(u);
		ranik[v] = min(ranik[v], ranik[u]);
	}
	if (ranik[v] == INF) ranik[v]=0;
	ranik[v]++;
	
	if(g[v].size()==1)
	{
		auto u = g[v][0];
		swap(setik[v], setik[u]);
		swap(dp[v], dp[u]);
		//setik[u].clear();
		int val{dp[v].back()};
		while (setik[v].contains(val))
		{
			val++;
		}
		dp[v].push_back(val);
		setik[v].insert(val);
		return;
	}
	dp[v].resize(ranik[v] + 1);
	set<int> mex;
	for(int i=1;i<=ranik[v];i++)
	{
		for(auto u :g[v])
		{
			dp[v][ranik[v] - i] ^= dp[u][ranik[u]+1 - i];
		}
		setik[v].insert(dp[v][ranik[v] - i]);
		mex.insert(dp[v][ranik[v] - i]);
	}
	int val = 0;
	while (setik[v].contains(val))
	{
		val++;
	}
	setik[v].insert(val);
	dp[v].back() = val;
	return;
}


