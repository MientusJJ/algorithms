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
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int maxik = 2e5 + 7;
const int maxn = 1 << 18;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;


int n;
string yikes;
ll ans = 0;
string essunia;
int hop[maxik];
int big[maxik];
int kmp(string cand);
void pre(string cand);

int main()
{
	es;
	cin >> yikes;
	cin >> n;
	while (n--)
	{
		cin >> essunia;
		if (essunia.size() > 1)
		{
			ans += kmp(essunia);
		}
	}

	cout << ans;
	return 0;
}
int kmp(string cand)
{
	memset(big, 0, sizeof big);
	cand = ' ' + cand;
	pre(cand);
	int j = 0;
	for (int i = 0; i < yikes.size(); i++)
	{
		while (j && cand[j+1] !=yikes[i])
		{
			j = hop[j];
		}
		if (cand[j + 1] == yikes[i])
		{
			j++;
		}
		if (!i)
		{
			big[i] = j;
		}
		else
		{
			big[i] = max(big[i - 1], j);
		}
	}
	reverse(cand.begin() + 1, cand.end());
	pre(cand);
	j = 0;
	for (int i = yikes.size() - 1; i + 1; i--)
	{
		while (j && cand[j + 1] != yikes[i])
		{
			j = hop[j];
		}
		if (cand[j + 1] == yikes[i])
		{
			j++;
		}
		if (j + big[i - 1]+1 >= cand.size() && big[i-1]>0)
		{
			return 1;
		}
	}
	return 0;
}
void pre(string cand)
{
	memset(hop, 0, sizeof hop);
	int i = 0, j = 2;
	for (j; j < cand.size(); j++)
	{
		while (i && cand[i+1]!=cand[j])
		{
			i = hop[i];
		}
		if (cand[i + 1] == cand[j])
		{
			i++;
		}
		hop[j] = i;
	}
	return;
}
