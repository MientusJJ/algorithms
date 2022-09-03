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
#define fi first
#define se second
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
const double PI = acos(-1.);

int n, m;
vector<int> d;
vector<pii> f;
priority_queue<pii> q;
vector<vector<int>> g;
vector<int> w;
vector<int> ans;
vector<bool> dVis, fVis;

int main()
{
	es;
	//	txt;
	cin >> n >> m;
	d.resize(n + 1, 0);
	f.resize(m + 1, { 0,0 });
	g.resize(n + 1);
	w.resize(n + 1, 0);
	dVis.resize(n + 1, false);
	fVis.resize(m + 1, false);
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> f[i].fi >> f[i].se;
		g[f[i].fi].push_back(i);
		g[f[i].se].push_back(i);
		w[f[i].fi]++;
		w[f[i].se]++;
	}
	for (int i = 1; i <= n; i++)
	{
		q.push({ d[i] - w[i], i });
	}
	while (q.size())
	{
		auto dish = q.top();
		q.pop();
		if (dVis[dish.se])
		{
			continue;
		}
		dVis[dish.se] = 1;
		if (dish.fi < 0)
		{
			break;
		}
		for (int v : g[dish.se])
		{
			if (fVis[v])
			{
				continue;
			}
			fVis[v] = 1;
			ans.push_back(v);
			if (f[v].first == dish.second)
			{
				swap(f[v].first, f[v].second);
			}
			w[f[v].first]--;
			q.push({ d[f[v].first] - w[f[v].first],f[v].first });
		}
	}
	if (ans.size() == m)
	{
		cout << "alive" << endl;
		for (int i = ans.size() - 1; i >= 0; i--)
		{

			cout << ans[i] << " ";
		}
	}
	else
	{
		cout << "dead" << endl;
	}
	return 0;
}
