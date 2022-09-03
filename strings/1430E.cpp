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
const int maxN = 1 << 18;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;


int n;
string s, rev;
ll tab[maxik];
ll ans;
int sTree[maxN * 2];
void upd(int value);
int show(int r, int l = 1, int ll = 1, int rr = maxN, int indx = 1);
queue<int> xD[30];
int main()
{
	cin >> n;
	cin >> s;
	rev = s;
	memset(sTree, 0, sizeof sTree);
	reverse(rev.begin(), rev.end());
	for (int i = 0; i < n; i++)
	{
		xD[s[i] - 'a'].push(i);
	}
	for (int i=0; i < n; i++)
	{
		tab[i] = xD[rev[i] - 'a'].front()+1 ;
		xD[rev[i] - 'a'].pop();
	}
	for (int i = n - 1; i+1; i--)
	{
		ans += show(tab[i]);
		upd(tab[i]);
	}
	cout << ans;
	return 0;
}
void upd(int value)
{
	int indx = value + maxN - 1;
	while (indx)
	{
		sTree[indx]++;
		indx /= 2;
	}
	return;
}
int show(int r, int l, int ll, int rr, int indx)
{
	if (ll > rr || l > rr || r < ll)
	{
		return 0;
	}
	if (ll >= l && rr <= r)
	{
		return sTree[indx];
	}
	int mid=(ll + rr) >> 1;
	return show(r, l, ll, mid, indx * 2) + show(r, l, mid + 1, rr, indx * 2 + 1);
}
