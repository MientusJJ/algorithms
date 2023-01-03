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

int n, m;
int sz = 1;
vector<int> last, previk, val, res;
vector<vector<pii>> q;
vector<pii> sTree;
void upd(int indx, int val = INF);
void build(int l = 1, int r = sz, int indx = 1);
pii check(int l, int r, int LL = 1, int RR = sz, int indx = 1);
int main()
{
	es;
	cin >> n;
	val.resize(maxik); q.resize(maxik);
	last.resize(maxik); previk.resize(maxik);

	while (sz < n)
	{
		sz <<= 1;
	}
	sTree.resize(sz * 2, make_pair(INF, INF));
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
		previk[i] = last[val[i]];
		last[val[i]] = i;
	}
	build();
	cin >> m;
	res.resize(m + 1);
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		q[r].push_back({ l,i });
	}
	for (int i = 1; i <= n; i++)
	{
		if (previk[i])
		{
			upd(previk[i]);
		}
		for (auto v : q[i])
		{
			auto ans = check(v.first, i);
			if (ans.first < v.first)
			{
				res[v.second] = val[ans.second];
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}
void build(int l, int r, int indx)
{
	if (l == r)
	{
		if (l <= n)
		{
			sTree[indx] = make_pair(previk[l], l);
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, indx * 2);
	build(mid + 1, r, indx * 2 + 1);
	sTree[indx] = min(sTree[indx * 2], sTree[indx * 2 + 1]);
	return;
}
void upd(int indx, int val)
{
	indx += sz - 1;
	sTree[indx].first = val;
	indx /= 2;
	while (indx)
	{
		sTree[indx] = min(sTree[indx * 2], sTree[indx * 2 + 1]);
		indx /= 2;
	}
	return;
}
pii check(int l, int r, int LL, int RR, int indx)
{
	if (RR < LL || RR<l || LL>r)
	{
		return { INF,INF };
	}
	if (LL >= l && RR <= r)
	{
		return sTree[indx];
	}
	int mid = (LL + RR) >> 1;
	return min(check(l, r, LL, mid, indx * 2), check(l, r, mid + 1, RR, indx * 2 + 1));
}
