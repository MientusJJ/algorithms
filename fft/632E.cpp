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
const int maxN = 20;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik1 = 1e9 + 7;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;
const int modik3 = 1004535809;
vector<ll> f, g,rev;
int n, k, val, N, lg = 0, sizes;
void ntt(vector<ll> &a, ll modek,ll gene, bool inv = 0);
ll powik(ll number, ll power, ll modek);
int main()
{
	
	es;
//	txt;
	cin >> n >> k;
	f.resize(1 << 20, 0);
	g.resize(1 << 20, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		f[val] = g[val] = 1;
		N = max(N, val);
	}
	N *= k;
	while ((1<<lg)<N)
	{
		lg++;
	}
	sizes = 1 << lg;
	
	f.resize(sizes); g.resize(sizes); rev.resize(sizes, 0);
	for (int i=1,j=0;i<sizes;i++)
	{
		int bit = sizes >> 1;
		for(;j&bit;bit>>=1)
		{
			j ^= bit;
		}
		j ^= bit;
		rev[i] = j;
	}
	ntt(f, modik3,generatorModik2);
	ntt(g, modik2, generatorModik2);
	for (int i = 0; i < sizes; i++)
	{
		f[i] = powik(f[i], k, modik3);
		g[i] = powik(g[i], k, modik2);
	}
	ntt(f, modik3, generatorModik2,1);
	ntt(g, modik2, generatorModik2,1);
	for (int i = 0; i <= N; i++)
	{
		if ( g[i]||f[i])
		{
			cout << i << " ";
		}
	}
	return 0;
}
void ntt(vector<ll> &a, ll modek, ll gene, bool inv)
{
	
	for (int i = 0; i < sizes; i++)
	{
		if (i < rev[i])
		{
			swap(a[i], a[rev[i]]);
		}
	}
	for (int len = 2; len <= sizes; len *= 2)
	{
		ll omegaLen = inv ? powik(gene, modek - 2, modek) : gene;
		omegaLen = powik(omegaLen, (modek - 1) / len, modek);
		for (int i = 0; i < sizes; i += len)
		{
			ll w = 1;
			for (int j = 0; j < len / 2; j++)
			{
				int u = a[i + j];
				int v = (int)((1LL * a[i + j + len / 2] * w) % modek);
				a[i + j] = (u + v) % modek;
				a[i + j + len / 2] = (u - v + modek) % modek;
				w *= omegaLen;
				w %= modek;
			}
		}
		
	}
	if (inv)
	{
		int invS = powik(sizes, modek - 2, modek);
		for (ll &x : a)
		{
			x = int((1ll * x*invS) % modek);
		}
	}
	return;
}
ll powik(ll number, ll power, ll modek)
{
	if (!power)
	{
		return 1ll;
	}
	if (power % 2)
	{
		return (number*powik(number, power - 1, modek)) % modek;
	}
	else
	{
		ll val = powik(number, power / 2, modek) % modek;
		return (val*val) % modek;
	}
}
