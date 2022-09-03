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
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
//#define TXTcreate freopen("C:/Temp/output.txt","w",stdout);freopen("input.txt","w",stdout);
#define TXT  freopen("C:/Temp/input.txt","r",stdin); freopen("C:/Temp/output.txt","w",stdout);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 64;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-14;
const pdd model = { 1.0,0.0 };
int n, q;
pdd sTree[maxN * 2];
inline double makeU(double p);
void buildTree(int l = 1, int r = maxN, int indx = 1);
void upd(int indx);
pdd  query(int l, int r, int LL = 1, int RR = maxN, int indx = 1);
int main()
{
	es;
	prec(10);
	//TXT;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		double p = (double)a / (double)b;
		double u = makeU(p);
		sTree[maxN + i] = { u,u };
	}
	buildTree();
	for (int i = 0; i < q; i++)
	{
		int digit;
		cin >> digit;
		if (digit - 1)
		{
			int a, b;
			cin >> a >> b;
			pdd ret = query(a, b);
			double res = 1.0 / (1 + ret.second);
			if (isnan(res))
			{
				res = 0.0;
			}
			cout << res << endl;
		
		}
		else
		{
			int a, b,in;
			cin >> in >> a >> b;
			double p = (double)a / (double)b;
			double u = makeU(p);
			sTree[maxN - 1 + in] = { u,u };
			upd(in);
		}
	}

	return 0;
}
inline double makeU(double p)
{
	return (1.0 - p) / p;
}
void buildTree(int l, int r , int indx )
{
	if(l==r)
	{
		if ((abs(sTree[indx].first) < eps) &&(abs(sTree[indx].second) < eps))
		{
			sTree[indx] = model;
		}
		return;
	}
	int mid = (l + r) >> 1;
	buildTree(l, mid, indx * 2);
	buildTree(mid+1, r, indx * 2|1);
	pdd  &ll = sTree[indx*2];
	pdd &rr = sTree[indx * 2 | 1];
	sTree[indx] = { ll.first*rr.first,ll.second + rr.second*ll.first };
	return;
}
void upd(int indx)
{
	indx += maxN - 1;
	indx /= 2;
	while (indx)
	{
		pdd &ll = sTree[indx * 2];
		pdd &rr = sTree[indx * 2 | 1];
		sTree[indx] = { ll.first*rr.first,ll.second + rr.second*ll.first };
		indx /= 2;

	}
}
pdd query(int l, int r, int LL, int RR, int indx)
{
	if ( RR< LL  || l > RR || r < LL)
	{
		return model;
	}
	if (l <= LL && r >= RR)
	{
		return sTree[indx];
	}
	pdd left, right, ret;
	int mid = (LL + RR) >> 1;
	left = query(l, r, LL, mid, indx * 2);
	right= query(l, r,mid+1,RR, indx * 2|1);
	ret = { left.first*right.first,left.second + right.second*left.first };
	return ret;
}
