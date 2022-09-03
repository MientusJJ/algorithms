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
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define Y cout << "YES" << "\n";
#define N cout << "NO" << "\n";
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxik = 1e5 + 7;
const int maxN = 1e1;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

int sa[maxik], snotA[maxik], ta[maxik], tnotA[maxik];
string s, t;
int main()
{
	es;
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	for (int i = 1; i < s.size(); i++)
	{
		snotA[i] += snotA[i - 1];
		if (s[i] == 'A')
		{
			sa[i]++;
			sa[i] += sa[i - 1];
		}
		else
		{
			sa[i]=0;
			snotA[i]++;
		}
	}
	for (int i = 1; i < t.size(); i++)
	{
		tnotA[i] += tnotA[i - 1];
		if (t[i] == 'A')
		{
			ta[i]++;
			ta[i] += ta[i - 1];
		}
		else
		{
			ta[i] = 0;
			tnotA[i]++;
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int ls, rs, lt, rt;
		cin >> ls >> rs >> lt >> rt;
		int notAinS = snotA[rs] - snotA[ls - 1];
		int notAinT= tnotA[rt] - tnotA[lt - 1];
		if (notAinS > notAinT) 
		{
			cout << 0;
			continue;
		}
		else
		{
			int aS = min(sa[rs], rs - ls + 1), aT = min(ta[rt], rt - lt + 1);
			if (aS<aT || notAinS%2!=notAinT%2 ||(aS==aT &&!notAinS && notAinT ))
			{
				cout << "0";
				continue;
			}
			if (notAinT > notAinS || aS % 3 == aT % 3)
			{
				cout << "1";
				continue;
			}
			cout << "0";
		}
	}
	return 0;
}
