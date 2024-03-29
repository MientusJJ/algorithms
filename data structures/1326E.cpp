#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define DEBUG


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

struct node
{
	int val = 0;
	int lazy = 0;
};
vector<int> places, q;
vector<node> sTree;
int n;
int sz = 1;
void upd(int l, int r, int val, int indx=1, int LL=1, int RR=sz);
int main()
{
	es;
	cin >> n;
	while (sz<n)
	{
		sz <<= 1;
	}
	sTree.resize(sz * 2);
	places.resize(n + 1);
	q.resize(n + 1);
	int res = n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		places[x] = i;

	}
	for(int i=1;i<=n;i++)
	{
		cin >> q[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i>1)
		{
			upd(1, q[i-1], -1);
		}
		while(sTree[1].val<=0)
		{
			upd(1, places[res--], 1);
		}
		cout << res + 1 << " ";
	}
	return 0;
}
void upd(int l, int r, int val, int indx, int LL, int RR)
{
	if(RR < LL || RR<l || LL>r)
	{
		return;
	}
	if(LL>=l && RR<=r)
	{
		sTree[indx].lazy += val;
		sTree[indx].val += val;
		return;
	}
	int mid = (LL + RR) >> 1;
	if(sTree[indx].lazy)
	{
		sTree[indx * 2].lazy += sTree[indx].lazy;
		sTree[indx * 2+1].lazy += sTree[indx].lazy;
		sTree[indx * 2].val += sTree[indx].lazy;
		sTree[indx * 2+1].val += sTree[indx].lazy;
		sTree[indx].lazy = 0;
	}
	upd(l, r, val, indx * 2, LL, mid);
	upd(l, r, val, indx * 2 + 1, mid + 1, RR);
	sTree[indx].val = max(sTree[indx * 2].val, sTree[indx * 2 + 1].val);
	return;
}
