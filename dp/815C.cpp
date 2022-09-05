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
const int maxik = 5e3 + 7;
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

vector<vector<int>> g;
vector<int> child;
ll n, b;
int c, d, x;
int dp[maxik][maxik][tight];
//vector<vector<vector<int>>> dp;
void dfs(int v=1);
int res = 0;
int main()
{
	es;
	//txt;
	cin >> n >> b;
	cin >> c >> d;
	g.resize(n + 1);
	child.resize(n + 1, 1);
	mst(dp, INF);
	//dp()
	/*dp.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		dp[i].resize(n + 1);
		for (int j = 0; j <= n; j++)
		{
			dp[i][j].resize(2,b+1);
		}
	}*/
	dp[1][1][0] = c;
	dp[1][1][1] = c - d;
	dp[1][0][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		cin >> c >> d >> x;
		g[x].push_back(i);
		dp[i][1][0] = c;
		dp[i][1][1] = c-d;
		dp[i][0][0] = 0;
	}
	dfs();
	for (int i = n; i + 1; i--)
	{
		if (dp[1][i][0] <= b || dp[1][i][1] <= b)
		{
			res = i;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
void dfs(int v)
{
	int a = 1;
	for (int u : g[v])
	{
		dfs(u);


		child[v] += child[u];
		for (int i = a; i+1; i--)
		{
			for (int j = 0; j <= child[u]; j++)
			{
				dp[v][i + j][0] = min(dp[v][i + j][0], dp[u][j][0] + dp[v][i][0]);
				dp[v][i + j][1] = min(dp[v][i + j][1], dp[v][i][1] + min(dp[u][j][1], dp[u][j][0]));
			}
		}
		a += child[u];
	}
	return;
}
