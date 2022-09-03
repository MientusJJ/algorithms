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
const int maxik = 1e6 + 7;
const int maxN = 1 << 20;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;

vector<pii> vert[maxik];
vector<int> bX[maxik], eX[maxik];
int n, m;
vector<int> sTree;
ll query(int l, int r, int indx = 1, int LL = 1, int RR = maxN);
ll res = 1;
void add(int indx, int val);
int main()
{
	es;
	//txt;
	sTree.resize(maxN * 2, 0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x1, x2, y;
		cin >> y >> x1 >> x2;
		x1++, x2++,y++;
		if (x1 == 1 && x2 == 1e6+1) res++;
		bX[x1].push_back(y);
		eX[x2].push_back(y);
	}
	for (int i = 0; i < m; i++)
	{
		int y1, y2, x;
		cin >> x >> y1 >> y2;
		x++, y2++, y1++;
		if (y1 == 1 && y2 == 1e6+1) res++;
		vert[x].push_back({ y1,y2 });
	}
	for (int i = 1; i <= 1e6+1; i++)
	{
		for (int x : bX[i])
		{
			add(x, 1);
		}
		for (pii p : vert[i])
		{
			res += query(p.first, p.second);
		}
		for (int x : eX[i])
		{
			add(x, -1);
		}
	}
	cout << res << endl;
	return 0;
}
void add(int indx, int val)
{
	indx += maxN - 1;
	sTree[indx] += val;
	indx /= 2;
	while (indx)
	{
		sTree[indx] = sTree[indx * 2] + sTree[indx * 2 + 1];
		indx /= 2;
	}
	return;
}
ll query(int l, int r, int indx, int LL, int RR)
{
	if (LL > r || RR < LL || RR < l)
	{
		return 0ll;
	}
	if (LL >= l && RR <= r)
	{
		return sTree[indx];
	}
	int mid = (LL + RR) >> 1;
	return query(l, r, indx * 2, LL, mid) + query(l, r, indx * 2 + 1, mid + 1, RR);
}
