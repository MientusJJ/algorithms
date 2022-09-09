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

int a[maxik],previk[maxik],root[maxik],sum[maxik*maxN],leftik[maxik*maxN],rightik[maxik*maxN],nxt[maxik];
int n,h=0,sz,s=0;
void upd(int &val, int x, int a, int l, int r);
int query(int val, int l, int r, int k);
int main()
{
	es;
	//txt;
	cin >> n;
	while ((1 << h) < (n+1))
	{
		h++;
	}
	sz = 1 << h;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = n; i; i--)
	{
		nxt[i] = previk[a[i]] ? previk[a[i]] : n + 1;
		previk[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (previk[i])
		{
			upd(root[1], previk[i], 1, 1, n + 1);
		}
	}
	for (int i = 2; i <= n; i++)
	{
		root[i] = root[i - 1];
		upd(root[i], i - 1, -1, 1, n + 1);
		upd(root[i], nxt[i - 1], 1, 1, n + 1);
	}
	for (int k = 1; k <= n; k++)
	{
		int i = 1, ans = 0;
		while (i<=n)
		{
			i = query(root[i], 1, n + 1, k + 1);
			ans++;
		}
		cout << ans << " ";
	}
	return 0;
}
void upd(int &val, int x, int a, int l, int r)
{
	int lastik = val;
	val = ++s;
	sum[val] = sum[lastik] + a;
	leftik[val] = leftik[lastik];
	rightik[val] = rightik[lastik];
	if (l == r) return;
	int mid = (l + r) >> 1;
	x <= mid ? upd(leftik[val], x, a, l, mid) : upd(rightik[val], x, a, mid + 1, r);
	return;
}
int query(int val, int l, int r, int k)
{
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) >> 1;
	if (sum[leftik[val]] >= k)
	{
		return query(leftik[val], l, mid, k);
	}
	else
	{
		return query(rightik[val], mid + 1, r, k - sum[leftik[val]]);
	}
	return 0;
}
