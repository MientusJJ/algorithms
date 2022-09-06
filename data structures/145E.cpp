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
void pushup(int indx);
void swapik(int indx);
struct numeros
{
	int c4=0, c7=0, c47=0, c74=0;
	bool c = false;
};
string s;
vector<numeros> sTree;
int t=0, m, n,sz;
void build(int indx=1,int l = 1, int r = sz);
void upd(int l, int r, int indx=1, int LL=1, int RR=sz);
void pushup(int indx);
void swapik(int indx);
void pushdown(int indx);
int main()
{
	es;
	//txt;
	cin >> n >> m;
	while ((1<<t)<n)
	{
		t++;
	}
	sz = 1 << t;
	sTree.resize(sz*2);
	cin >> s;
	s = " " + s;
	build();
	while (m--)
	{
		cin >> s;
		if (s[0] == 'c')
		{
			cout << max(sTree[1].c4, max(sTree[1].c7, sTree[1].c47));
			cout << endl;
		}
		else
		{
			int l, r;
			cin >> l >> r;
			upd(l, r);
		}
	}
	return 0;
}
void upd(int l, int r, int indx, int LL, int RR)
{
	if (LL > r || LL > RR || RR < l)
	{
		return;
	}
	if (LL >= l && RR <= r)
	{
		swapik(indx);
		return;
	}
	pushdown(indx);
	int mid = (LL + RR) >> 1;
	upd(l, r, indx * 2, LL, mid);
	upd(l, r, indx * 2 + 1, mid + 1, RR);
	pushup(indx);
	return;
}
void build(int indx, int l, int r)
{
	if (l > n)
	{
		return;
	}
	if (l == r )
	{
		if (s[l]=='7')
		{
			sTree[indx].c7++;
		}
		else
		{
			sTree[indx].c4++;
		}
		sTree[indx].c47 = sTree[indx].c74 = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(indx * 2, l, mid);
	build(indx * 2 + 1, mid + 1, r);
	pushup(indx);
	return;
}
void pushup(int indx)
{
	sTree[indx].c4 = sTree[indx * 2].c4 + sTree[indx * 2 + 1].c4;
	sTree[indx].c7 = sTree[indx * 2].c7 + sTree[indx * 2 + 1].c7;
	sTree[indx].c47 = max(sTree[indx * 2].c4 + sTree[indx * 2 + 1].c47, sTree[indx * 2].c47 + sTree[indx * 2 + 1].c7);
	sTree[indx].c74 = max(sTree[indx * 2].c7 + sTree[indx * 2 + 1].c74, sTree[indx * 2].c74 + sTree[indx * 2 + 1].c4);
	return;
}
void swapik(int indx)
{
	swap(sTree[indx].c4, sTree[indx].c7);
	swap(sTree[indx].c47, sTree[indx].c74);
	sTree[indx].c ^= 1;
	return;
}
void pushdown(int indx)
{
	if (sTree[indx].c)
	{
		sTree[indx].c ^= 1;
		swapik(indx * 2);
		swapik(indx * 2 | 1);
	}
	return;
}
