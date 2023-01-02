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
const int maxik = 3e5 + 7;
const int maxN = 19;
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
int sz = 1 << maxN;
vector<int>sTree;
queue<int> qA[maxik];
vector<int> a, b, countA, countB;
int t, n;
void solve();
void build(int indx = 1, int l = 1, int r = sz);
void upd(int indx);
int query(int l, int r, int LL = 1, int RR = sz, int indx = 1);
int main()
{
	es;
	cin >> t;
	while (t--)
	{
		solve();
	}
}
void solve()
{
	int temp = 1;
	cin >> n;
	while (temp < n)
	{
		temp <<= 1;
	}
	sz = temp;
	a.clear(), b.clear(), countA.clear(), countB.clear();
	a.resize(n + 1,0);
	b.resize(n + 1,0);
	countA.resize(n + 1,0);
	countB.resize(n + 1, 0);
	sTree.resize(sz * 2, INF);
	for(int i=1;i<=n;i++)
	{
		while (qA[i].size())
		{
			qA[i].pop();
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		qA[a[i]].push(i);
		sTree[sz - 1 + i] = a[i];
		countA[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		countB[b[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (countA[i] != countB[i])
		{
			cout << "NO" << endl;
			return;
		}
	}
	build();
	for (int i = 1; i <= n; i++)
	{
		int pos = qA[b[i]].front();
		qA[b[i]].pop();
		int places = query(1, pos);
		if (places < b[i])
		{
			cout << "NO" << endl;
			return;
		}
		upd(pos);
	}
	cout << "YES" << endl;
}
void build(int indx, int l, int r)
{
	if (l == r)
	{
		return;
	}
	int mid{ (l + r) / 2 };
	build(indx * 2, l, mid);
	build(indx * 2 | 1, mid + 1, r);
	sTree[indx] = min(sTree[indx * 2], sTree[indx * 2 | 1]);
}

void upd(int indx)
{
	indx += sz - 1;
	sTree[indx] = INF;
	indx /= 2;
	while (indx)
	{
		sTree[indx] = min(sTree[indx * 2], sTree[indx * 2 | 1]);
		indx /= 2;
	}
	return;
}
int query(int l, int r, int LL, int RR, int indx)
{
	if (LL > r || LL > RR || RR < l)
	{
		return INF;
	}
	if (LL >= l && RR <= r)
	{
		return sTree[indx];
	}
	int mid{ (LL + RR) / 2 };
	return min(query(l, r, LL, mid, indx * 2), query(l, r, mid + 1, RR, indx * 2 | 1));
}
