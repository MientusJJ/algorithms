

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
const int maxN = 60;
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
int r, g;
vector<int> islands;
vector<vector<int>> walk;
deque<pii> q;
ll ans = INFll;
int main()
{
	es;
	//txt;
	cin >> n >> m;
	islands.resize(m);

	for (int &a : islands)
	{
		cin >> a;
	}
	sort(all(islands));
	cin >> g >> r;
	walk.resize(m, vector<int>(g, INF));
	walk[0][0] = 0;
	q.push_front({ 0,0 });
	while (q.size())
	{
		auto[isl, times] = q.front();
		q.pop_front();
		if (isl + 1 < m)
		{
			int y = islands[isl + 1] - islands[isl]+times;
			if (walk[isl + 1][y % g] == INF)
			{
				if (y < g)
				{
					walk[isl + 1][y] = walk[isl][times];
					q.push_front({ isl + 1, y });
				}
				else if (y == g)
				{
					walk[isl + 1][0] = walk[isl][times]+1;
					q.push_back({ isl + 1,0 });
				}
			}
		}
		if (isl)
		{
			int y = islands[isl ] - islands[isl-1] + times;
			if (walk[isl -1][y % g] == INF)
			{
				if (y < g)
				{
					walk[isl -1][y] = walk[isl][times];
					q.push_front({ isl -1, y });
				}
				else if (y == g)
				{
					walk[isl -1][0] = walk[isl][times] + 1;
					q.push_back({ isl-1,0 });
				}
			}
		}
	}
	if (walk[m - 1][0] != INF)
	{
		ans = (ll)walk[m - 1][0] * (g + r) - r;
	}
	for (int i = 1; i < g; i++)
	{
		if (walk[m - 1][i] != INF)
		{
			ans = min(ans,(ll) walk[m - 1][i] * (g + r) + i);
		}
	}
	cout << (ans != INFll ? ans : -1) << endl;
	return 0;
}
