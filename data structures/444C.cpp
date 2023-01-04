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

struct cell
{
	ll sum{ 0 };
	ll color{ 0 };
	ll flag{ 0 };
	ll lazy{ 0 };
};
int n, m;
int sz = 1;
int c;
vector<cell> sTree;
ll check(int l, int r, int LL=1, int RR=sz, int indx=1);
void upd(int l, int r, ll x, int LL = 1, int RR = sz, int indx = 1);
void pushdown(ll indx, int LL, int RR, int mid);
int main()
{

	es;
	cin >> n >> m;
	while (sz<n)
	{
		sz <<= 1;
	}
	sTree.resize(sz * 2);
	for(int i=1;i<=n;i++)
	{
		sTree[sz + i - 1].color =i;
	}
	while(m--)
	{
		cin >> c;
		if(c==1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			upd(l, r, x);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << check(l, r) << "\n";
		}
	}
	return 0;
}
void pushdown(ll indx, int LL, int RR, int mid)
{
	sTree[indx * 2].sum += sTree[indx].flag * (mid - LL + 1);
	sTree[indx * 2 | 1].sum += sTree[indx].flag * (RR - mid);
	sTree[indx * 2 | 1].flag += sTree[indx].flag;
	sTree[indx * 2].flag += sTree[indx].flag;
	sTree[indx * 2].color = sTree[indx * 2 | 1].color = sTree[indx].lazy;
	sTree[indx * 2].lazy = sTree[indx * 2 | 1].lazy = sTree[indx].lazy;
	sTree[indx].flag = 0;
	sTree[indx].lazy = 0;
	return;
}
ll check(int l, int r, int LL, int RR, int indx)
{
	if(LL> RR || RR<l || LL>r)
	{
		return 0ll;
	}
	if(LL>=l && RR<=r)
	{
		return sTree[indx].sum;
	}
	int mid = (LL + RR) >> 1;
	if (sTree[indx].flag)
	{
		pushdown(indx, LL, RR,mid);
	}
	return check(l, r, LL, mid, indx * 2) + check(l, r, mid + 1, RR, indx * 2 | 1);
}
void upd(int l, int r, ll x, int LL, int RR, int indx)
{
	if (LL > RR || RR<l || LL>r)
	{
		return;
	}
	if (LL >= l && RR <= r && sTree[indx].color)
	{
		sTree[indx].sum += (RR - LL + 1) * abs(x - sTree[indx].color);
		sTree[indx].flag += abs(x - sTree[indx].color);
		sTree[indx].color = sTree[indx].lazy=x;
		return;
	}
	int mid = (LL + RR) >> 1;
	if (sTree[indx].flag)
	{
		pushdown(indx, LL, RR, mid);
	
	}
	upd(l, r, x, LL, mid, indx * 2);
	upd(l, r, x, mid + 1, RR, indx * 2 | 1);
	if (sTree[indx*2].color==sTree[indx*2|1].color)
	{
		sTree[indx].color = sTree[indx * 2].color;
	}
	else
	{
		sTree[indx].color = 0;
	}
	sTree[indx].sum = sTree[indx * 2].sum + sTree[indx * 2 | 1].sum;
	return;
}
