#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 1<<17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

int sTreeGcd[2 * maxik],sTreeCount[2*maxik];
int t, n;
void build(int indx = 1, int l = 1, int r = maxik);
int check(int l, int r, int L = 1, int R = maxik, int indx = 1);
int counting(int l, int r, int gcd, int L=1, int R = maxik, int indx = 1);
int main()
{
	es;
	for (int i = 1; i < 2 * maxik; i++)
	{
		sTreeGcd[i] = INF;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sTreeGcd[i + maxik];
		sTreeCount[i + maxik]=1;
	}
	build();
	cin >> t;
	while (t--)
	{
		int l, r;
		cin >> l >> r;
		int p=check(l, r);
		cout << r + 1 - l - counting(l, r, p);
		//cout << " ODP \n";
		cout << "\n";
	}
	return 0;
}
void build(int indx, int l, int r)
{
	if (l>=r )
	{
		return;
	}
	int mid = (l + r) >> 1;
	build(indx * 2, l, mid);
	build(indx * 2 + 1, mid + 1, r);
	if (sTreeGcd[indx * 2] != INF && sTreeGcd[indx * 2+1] != INF)
	{
		sTreeGcd[indx] = gcd(sTreeGcd[indx * 2], sTreeGcd[indx * 2 + 1]);
	}
	else if (sTreeGcd[indx * 2] == INF)
	{
		sTreeGcd[indx]=sTreeGcd[indx * 2+1];
	}
	else
	{
		sTreeGcd[indx]= sTreeGcd[indx * 2];
	}
	

	if (sTreeGcd[indx] == sTreeGcd[indx * 2])
	{
		sTreeCount[indx] += sTreeCount[indx * 2];
	}
	if (sTreeGcd[indx] == sTreeGcd[indx * 2 + 1])
	{
		sTreeCount[indx] += sTreeCount[indx * 2+1];
	}
	return;
}
int check(int l, int r, int L, int R, int indx)
{
	if (L > r || R < l || R<L)
	{
		return INF;
	}
	if (L >= l && R <= r)
	{
		return sTreeGcd[indx];
	}
	int mid = (L + R) >> 1;
	int a = check(l, r, L, mid, indx * 2);
	int b = check(l, r, mid + 1, R, indx * 2 + 1);
	if (a != INF && b != INF)
	{
		return gcd(a, b);
	}
	else if (a == INF)
	{
		return b;
	}
	else
	{
		return a;
	}


}
int counting(int l, int r, int gcd, int L, int R, int indx)
{
	if (L > r || R < l || R < L)
	{
		return 0;
	}
	if (L >= l && R <= r)
	{
		if (sTreeGcd[indx] == gcd)
		{
			return sTreeCount[indx];
		}
		else
		{
			return 0;
		}
	}
	int mid = (L + R) >> 1;
	return counting(l, r, gcd, L, mid, indx * 2) + counting(l, r, gcd, mid + 1, R, indx * 2 + 1);
}
