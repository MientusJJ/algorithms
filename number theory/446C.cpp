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
const int maxik = 3e5 + 7;
const int maxN = 1 << 19;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;
struct node
{
	ll f1=0;
	ll f2=0;
	ll val = 0;
};
const ll sModik = 1e9 + 9;
node sTree[maxN * 2];
 ll Fib[maxik];
void build(int l = 1, int r = maxN, int indx = 1);
ll quebonafide(int l, int r, int indx = 1, int LL = 1, int RR = maxN);
void rhcp(int l, int r, int indx=1, int LL=1, int RR=maxN);
ll sumik(ll f1, ll f2, ll x);
ll Addfib(ll fib1, ll fib2, ll n);
int n, m;
int main()
{
	es;
	//txt;
	mst(sTree, 0);
	cin >> n >> m;
	Fib[1] = Fib[2] = 1;
	for (int i = 3; i <= maxik-5; i++)
	{
		Fib[i] = Fib[i - 1] + Fib[i - 2];
		Fib[i] %= sModik;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> sTree[maxN + i].val;
	}
	build();
	while (m--)
	{
		int sign,l,r;
		cin >> sign;
		cin >> l >> r;
		if (sign - 1)
		{
			cout << quebonafide(l,r) << endl;
		}
		else
		{
			rhcp(l, r);
		}
	}
	return 0;
}

void build(int l, int r, int indx)
{
	if (l == r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, indx * 2);
	build(mid+1,r, indx * 2+1);
	sTree[indx].val = sTree[indx * 2].val + sTree[indx * 2 + 1].val;
	sTree[indx].val %= sModik;
	return;
}
ll quebonafide(int l, int r, int indx, int LL, int RR)
{
	if (RR<LL || l>RR || r < LL)
	{
		return 0ll;
	}
	if (l <= LL && r >= RR)
	{
		return sTree[indx].val;
	}
	int mid = (LL + RR) >> 1;
	if (RR != LL)
	{
		sTree[indx * 2].val += sumik(sTree[indx].f1, sTree[indx].f2, mid - LL + 1);
		sTree[indx * 2].val %= sModik;
		sTree[indx * 2].f1 += sTree[indx].f1;
		sTree[indx * 2].f1 %= sModik;
		sTree[indx * 2].f2 += sTree[indx].f2;
		sTree[indx * 2].f2 %= sModik;

		sTree[indx * 2 + 1].val += sumik(Addfib(sTree[indx].f1, sTree[indx].f2, mid - LL), Addfib(sTree[indx].f1, sTree[indx].f2, mid - LL + 1), mid - LL + 1);
		sTree[indx * 2 + 1].val %= sModik;
		sTree[indx * 2 + 1].f1 += Addfib(sTree[indx].f1, sTree[indx].f2, mid - LL);
		sTree[indx * 2 + 1].f1 %= sModik;
		sTree[indx * 2 + 1].f2 += Addfib(sTree[indx].f1, sTree[indx].f2, mid - LL + 1);
		sTree[indx * 2 + 1].f2 %= sModik;


		sTree[indx].f1 = sTree[indx].f2 = 0;

	}
	return ((quebonafide(l, r, indx * 2, LL, mid) + quebonafide(l, r, indx * 2 + 1, mid + 1, RR))%sModik);
	
}
void rhcp(int l, int r, int indx, int LL, int RR)
{
	if (RR<LL || l>RR || r < LL)
	{
		return;
	}
	if (l <= LL && RR<=r)
	{
		sTree[indx].f1 += Fib[LL - l + 1];
		sTree[indx].f1 %= sModik;
		if (RR != LL)
		{
			sTree[indx].f2 += Fib[LL - l + 2];
			sTree[indx].f2 %= sModik;
		}
		sTree[indx].val += sumik(Fib[LL - l + 1], Fib[LL - l + 2], RR - LL + 1);
		sTree[indx].val %= sModik;
		return;
	}
	int mid=(LL + RR) >> 1;
	if (RR != LL)
	{
		sTree[indx*2].val += sumik(sTree[indx].f1, sTree[indx].f2, mid - LL + 1);
		sTree[indx*2].val %= sModik;
		sTree[indx * 2].f1 += sTree[indx].f1;
		sTree[indx*2].f1 %= sModik;
		sTree[indx * 2].f2 += sTree[indx].f2;
		sTree[indx * 2].f2 %= sModik;

		sTree[indx * 2+1].val += sumik(Addfib(sTree[indx].f1, sTree[indx].f2,mid-LL), Addfib(sTree[indx].f1, sTree[indx].f2, mid - LL+1), mid - LL + 1);
		sTree[indx * 2 + 1].val %= sModik;
		sTree[indx * 2 + 1].f1 += Addfib(sTree[indx].f1, sTree[indx].f2, mid - LL);
		sTree[indx * 2 + 1].f1 %= sModik;
		sTree[indx * 2 + 1].f2 += Addfib(sTree[indx].f1, sTree[indx].f2, mid - LL + 1);
		sTree[indx * 2 + 1].f2 %= sModik;


		sTree[indx].f1 = sTree[indx].f2 = 0;

	}
	rhcp(l, r, indx * 2, LL, mid);
	rhcp(l, r, indx * 2+1, mid+1, RR);
	sTree[indx].val = (sTree[indx * 2].val + sTree[indx * 2 + 1].val)%sModik;
	return;
}
ll Addfib(ll fib1, ll fib2, ll n)
{
	return (((fib1*Fib[n])%sModik)+ ((fib2*Fib[n+1]) % sModik)%sModik);
}
ll sumik(ll f1, ll f2, ll x)
{
	return (((Addfib(f1, f2, x) - f2)%sModik+sModik) % sModik);
}
