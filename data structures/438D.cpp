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
const int maxN = 26;
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
struct Node
{
	int tag = -1;
	int alpa[maxN];
};
vector<int> a;
vector<char> res;
int sz = 1;
vector<Node> sTree;
int n,m;
void build(int indx = 1, int l = 1, int r = sz);
void solve();
void query(vector<int> &v,int l, int r, int LL = 1, int RR = sz, int indx = 1);
void update(int c, int l, int r, int LL = 1, int RR = sz, int indx = 1);
void show(int indx = 1, int l = 1, int r = sz);
void down(int indx,int l,int r);
void up(int indx, int l, int r);
int main()
{
	es;
	cin >> n >> m;
	while(n>sz)
	{
		sz <<= 1;
	}
	a.resize(n+1);
	res.resize(n+1);
	sTree.resize(sz * 2);
	for(int i=1;i<=n;i++)
	{
		char c;
		cin >> c;
		a[i]=(c - 'a');
	}
	for(int i=1;i<=n;i++)
	{
		sTree[i + sz-1].alpa[a[i]]++;
		sTree[i + sz-1].tag = a[i];
	}
	build();
	while(m--)
	{
		solve();
	}
	show();
	for(int i=1;i<=n;i++)
	{
		cout << res[i];
	}
	return 0;
}
void build(int indx, int l, int r)
{
	if(l==r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	build(indx << 1, l, mid);
	build(indx << 1 | 1, mid + 1, r);
	up(indx, l, r);
	return;
}
void solve()
{
	int lr, rr, dir;
	cin >> lr >> rr >> dir;
	vector<int> v(maxN, 0);
	query(v, lr, rr);
	if(dir)
	{
		for (int j = 0, i = 0; i < maxN; i++)
		{
			if (v[i])
			{
				update(i, lr + j, lr + j + v[i] - 1);
				j += v[i];
			}
		}
	}
	else
	{
		for (int j = 0, i = maxN-1; i>=0; i--)
		{
			if (v[i])
			{
				update(i, lr + j, lr + j + v[i] - 1);
				j += v[i];
			}
		}
	}
	return;
}
void show(int indx, int l, int r)
{
	if(l>n)
	{
		return;
	}
	if(l==r && l<=n)
	{
		res[l] = sTree[indx].tag+'a';
		return;
	}
	down(indx, l, r);
	int mid = (l + r) >> 1;
	show(indx << 1, l, mid);
	show(indx << 1 | 1, mid + 1, r);
	return;
}
void query(vector<int>& v, int l, int r, int LL, int RR, int indx)
{
	if(RR<LL || RR<l ||LL>r)
	{
		return;
	}
	if(LL>=l && RR<=r)
	{
		for(int i=0;i<maxN;i++)
		{
			v[i] += sTree[indx].alpa[i];
		}
		return;
	}
	down(indx, LL, RR);
	int mid = (LL + RR) >> 1;
	query(v, l, r, LL, mid, indx << 1);
	query(v, l, r, mid + 1, RR, indx << 1 | 1);
	up(indx, LL, RR);
	return;

}
void down(int indx, int l, int r)
{
	if(sTree[indx].tag!=-1)
	{
		sTree[indx << 1].tag = sTree[indx << 1 | 1].tag = sTree[indx].tag;
		mst(sTree[indx << 1].alpa, 0);
		mst(sTree[indx << 1|1].alpa, 0);
		int mid =(l+r)>>1;
		sTree[indx << 1].alpa[sTree[indx << 1].tag] = mid + 1 - l;
		sTree[indx << 1 | 1].alpa[sTree[indx << 1 | 1].tag] = r - (mid);
		sTree[indx].tag = -1;
	}
	return;
}
void up(int indx, int l, int r)
{
	for (int i = 0; i < maxN; i++)
	{
		sTree[indx].alpa[i] = sTree[indx << 1].alpa[i] + sTree[indx << 1 | 1].alpa[i];
	}
	if (sTree[indx << 1].tag == sTree[indx << 1 | 1].tag && sTree[indx << 1 | 1].tag!=-1)
	{
		sTree[indx].tag = sTree[indx << 1].tag;
	}
}

void update(int c, int l, int r, int LL, int RR, int indx)
{
	if (RR < LL || RR<l || LL>r)
	{
		return;
	}
	if (LL >= l && RR <= r)
	{
		mst(sTree[indx].alpa, 0);
		sTree[indx].alpa[c] = RR-LL + 1;
		sTree[indx].tag = c;
		return;
	}
	down(indx,LL, RR);
	int mid = (LL + RR) >> 1;
	update(c, l, r, LL, mid, indx << 1);
	update(c, l, r, mid+1, RR, indx << 1|1);
	up(indx, LL, RR);
	return;
}
