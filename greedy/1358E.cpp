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

int n,h;
bool p;
vector<ll> a, pref; ll sec;
int main()
{
	es;
//	txt;
	cin >> n;
	a.resize((n + 1) / 2 + 1, 0);
	pref.resize(n+1, 0);
	for (int i = 1; i <= (n+1)/2; i++)
	{
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	cin >> sec;
	for (int i = (n + 3) / 2; i <= n; i++)
	{
		pref[i] = pref[i - 1] + sec;
	}
	bool t = true;
	int res = n;
	for (int i = 0; i + res <= n; i++)
	{
		while (pref[i+res]-pref[i]<=0 && res>(n+1)/2)
		{
			res--;
		}
		if (pref[i + res] - pref[i] <= 0)
		{
			t = false;
			break;
		}
	}
	if (t)
	{
		cout << res << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;
}
