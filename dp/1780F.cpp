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
const int maxik = 3e5 + 7;
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

vector<ll> a;
vector<ll> dp;
ll n;
int main()
{
	es;
	cin >> n;
	a.resize(maxik + 1, 0);
	dp.resize(maxik + 1, 0);
	for(ll i=1;i<=n;i++)
	{
		int val;
		cin >> val;
		a[val]++;
	}
	for(ll i=1;i<=maxik;i++)
	{
		a[i] += a[i - 1];
	}
	for(ll i= maxik;i;i--)
	{
		ll sum = 0,val=0;
		for(ll j=i;j<= maxik;j+=i)
		{
			if(a[j]!=a[j-1])
			{
				dp[i] += val * a[j - 1] - sum;
				val++;
				sum += a[j];
			}
		}
		for(ll j=2*i;j<= maxik;j+=i)
		{
			dp[i] -= dp[j];
		}
	}
	cout << dp[1];
	return 0;
}
