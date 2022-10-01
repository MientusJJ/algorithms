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
#ifdef DEBUG
fstream in("C:/Temp/input.txt", ios::in);
fstream out("C:/Temp/output.txt", ios::out | ios::trunc);
#define cin in
#define cout out
#endif // DEBUG 


int t,n;
void solve();
vector < vector<ll>> v;
vector<int> sum;
int main()
{
	es;
	cin >> t;
	while (t--) { 
		solve(); 
	}
	return 0;
}
void solve()
{
	ll result = 0;
	int bought = 0,togo;
	cin >> n;
	v.clear();
	sum.clear();
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	v.resize(n+1);
	sum.resize(n+1);
	for (int i = 1; i <=n; i++)
	{
		int m; ll p;
		cin >> m >> p;
		v[m].push_back(p);
	}
	sum[0] = v[0].size();
	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + v[i].size();
	}
	for (int i = n; i; i--)
	{
		for (ll p : v[i])
		{
			pq.push(p);
		}
		togo = max(0, i - bought - sum[i - 1]);
		while (pq.size() && togo)
		{
			result += pq.top();
			pq.pop();
			togo--, bought++;
		}
	}
	cout << result << endl;
	return;
}
