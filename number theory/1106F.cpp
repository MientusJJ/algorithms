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
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 1e2 + 7;
const int maxN = 1 << 20;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;


struct Matrix
{
	ll mat[maxik][maxik];

	Matrix()
	{
		memset(this->mat, 0, sizeof this->mat);
	}
	Matrix(int j)
	{
		memset(this->mat, 0, sizeof this->mat);
		for (int i = 0; i < maxik; i++)
		{
			this->mat[i][i] = j;
		}
	}
	Matrix operator*(const Matrix &b) const
	{
		Matrix res;
		for (int i = 0; i < maxik; i++)
		{
			for (int j = 0; j < maxik; j++)
			{
				for (int k = 0; k < maxik; k++)
				{
					res.mat[i][j] += this->mat[i][k] * b.mat[k][j] % (modik2-1);
					res.mat[i][j] %= (modik2 - 1);
				}
			}
		}
		return res;
	}
	friend Matrix operator^(Matrix a,ll power)
	{
		Matrix res(1);
		while (power)
		{
			if (power & 1)
			{
				res =res* a;
			}
			a = a * a;
			power >>= 1;
		}
		return res;
	}
};
ll powik(ll number, ll power, ll modek);
ll bsgs(ll b, ll a = generatorModik2, ll modek = modik2);
ll findAns(ll power, ll genepower, ll modek = modik2 - 1);
void  extEuclidean(ll a, ll b, ll &x, ll&y);
int n, k, m;
vector<ll> b;
Matrix matik;
int main()
{
	es;
	//txt;
	cin >> k;
	b.resize(k + 1);
	for (int i = 1; i <= k; i++)
	{
		cin >> b[i];
	}
	cin >> n >> m;
	ll fixedM=bsgs(m);
	for (int i = 1; i < b.size(); i++)
	{
		matik.mat[0][i - 1] = b[i];
	}
	for (int i = 1; i < k; i++)
	{
		matik.mat[i][i - 1] = 1;
	}
	matik=matik ^ (n - k);
	ll res = findAns(matik.mat[0][0], fixedM);
	if (res == -1)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << powik(generatorModik2, res, modik2) << endl;
	}
	return 0;
}
ll powik(ll number, ll power, ll modek)
{
	if (!power)
	{
		return 1ll;
	}
	if (power % 2)
	{
		return (number*(powik(number, power - 1,modek) % modek)) % modek;
	}
	else
	{
		ll ret = (powik(number, power / 2, modek) % modek);
		return (ret*ret) % modek;
	}
}
ll bsgs(ll b, ll a, ll modek)
{
	ll sq = (ll)sqrt(modek) + 1;
	map<ll, int> mp;
	ll curr = 1;
	for (int i = 0; i < sq; i++)
	{
		ll t = (powik(curr, modek - 2, modek)*b) % modek;
		if (!mp.count(t))
		{
			mp[t] = i;
		}
		curr *= a;
		curr %= modek;
	}
	ll opp = curr;
	curr = 1;
	for (ll i = 0; i <sq; i++)
	{
		if (mp.count(curr))
		{
			return sq * i + mp[curr];
		}
		curr *= opp;
		curr %= modek;
	}
	return -1ll;
}
ll findAns(ll power, ll genepower, ll modek)
{
	if (!genepower)
	{
		return 0ll;
	}
	ll bigGcd = gcd(modek, power);
	if (genepower%bigGcd)
	{
		return -1ll;
	}
	power /= bigGcd; genepower /= bigGcd; modek /= bigGcd;
	ll x, y;
	extEuclidean(power, modek, x, y);
	x *= genepower;
	x%=modek;
	x = (x + modek) % modek;
	return x;

}
void  extEuclidean(ll a, ll b, ll &x,ll&y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	extEuclidean(b, a%b, y, x);
	y -= x * (a / b);
	return;
}
