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
const int maxN = 1<<17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;



void init(int l = 1, int r = maxN,int indx=1);
const int hash1 = 29;
const int hash2 = 31;
ll hashTree1[maxN * 2], hashTree2[maxN * 2], wordTree1[maxN * 2], wordTree2[maxN * 2], lazyprop[maxN * 2];
int n, m, k,c;
char str;
void upd(int l, int r, int change, int L = 1, int R = maxN, int indx=1);
void query(int l, int r, ll &res1, ll &res2, int L = 1, int R = maxN, int indx = 1);
void repair(int indx);
int main()
{
	es;
	cin >> n >> m >> k;
	hashTree1[maxN] = hashTree2[maxN] = 1;
	for (int i = maxN; i < maxN+n; i++)
	{
		cin >> str;
		int s = int(str) - '0' + 1;
		if (i>maxN)
		{
			hashTree1[i] = hashTree1[i - 1] * hash1;
			hashTree1[i] %= modik;
			hashTree2[i] = hashTree2[i - 1] * hash2;
			hashTree2[i] %= modik;
		}
		wordTree1[i] = s * hashTree1[i];
		wordTree2[i] = s * hashTree2[i];
		wordTree1[i] %= modik;
		wordTree2[i] %= modik;
	}
	init();
	for (int i = 0; i < m + k; i++)
	{
		int c,l,r;
		cin >> c >> l >> r;
		if (c == 1)
		{
			int change;
			cin >> change;
			change++;
			upd(l, r, change);
		}
		else
		{
			int period;
			cin >> period;
			int range = r - l + 1;
			if (range<=period)
			{
				Y;
			}
			else
			{
				ll temp12=0, temp11=0, temp22=0, temp21=0;
				if (range <= 2 * period)
				{
					int p = range - period;
					query(l, l + p - 1, temp11, temp12);
					query(r-p+1, r, temp21, temp22);
					temp11 = (temp11*hashTree1[maxN + period]) % modik;
					temp12 = (temp12*hashTree2[maxN + period]) % modik;
					if (temp11 == temp21 && temp12 == temp22)
					{
						Y;
					}
					else
					{
						N;
					}
				}
				else
				{
					if (range%period)
					{
						int blk = range / period;
						int len = (blk - 1)*period;
						query(l, l + len - 1, temp11, temp12);
						query(l+period, l-1+period+len, temp21, temp22);
						temp11 = (temp11*hashTree1[maxN + period]) % modik;
						temp12 = (temp12*hashTree2[maxN + period]) % modik;
						if (temp11 == temp21 && temp12 == temp22)
						{
							temp12 = 0; temp11 = 0;  temp22 = 0; temp21 = 0;
							int t = range - blk * period;
							query(l, l +t-1, temp11, temp12);
							query(r-t+1, r, temp21, temp22);
							temp11 = (temp11*hashTree1[maxN + blk*period ]) % modik;
							temp12 = (temp12*hashTree2[maxN + blk * period]) % modik;
							if (temp11 == temp21 && temp12 == temp22)
							{
								Y;
							}
							else
							{
								N;
							}
						}
						else
						{
							N;
						}
					}
					else
					{
						int blk = range / period;
						int len = (blk - 1)*period;
						query(l, l + len - 1, temp11, temp12);
						query(r-len+1,r, temp21, temp22);
						temp11 = (temp11*hashTree1[maxN + period]) % modik;
						temp12 = (temp12*hashTree2[maxN + period]) % modik;
						if (temp11 == temp21 && temp12 == temp22)
						{
							Y;
						}
						else
						{
							N;
						}
					}
				}
			}
		}
	}
	return 0;
}
void init(int l,int r,int indx)
{
	if (r <= l)
	{
		return;
	}
	int mid = (l + r) >> 1;
	init(l, mid, indx * 2); init(mid + 1, r, indx * 2 + 1);
	hashTree1[indx] = hashTree1[indx * 2] + hashTree1[indx * 2 + 1];
	hashTree1[indx] %= modik;
	hashTree2[indx] = hashTree2[indx * 2] + hashTree2[indx * 2 + 1];
	hashTree2[indx] %= modik;
	wordTree2[indx] = wordTree2[indx * 2] + wordTree2[indx * 2 + 1];
	wordTree2[indx] %= modik;
	wordTree1[indx] = wordTree1[indx * 2] + wordTree1[indx * 2 + 1];
	wordTree1[indx] %= modik;
	return;
}
void upd(int l, int r, int change, int L, int R, int indx)
{
	if (r<L || l>R)
	{
		return;
	}
	if (L >= l && R <= r)
	{
		lazyprop[indx] = change;
		wordTree1[indx] = change * hashTree1[indx];
		wordTree1[indx] %= modik;
		wordTree2[indx] = change * hashTree2[indx];
		wordTree2[indx] %= modik;
		return;
	}
	int mid = (L + R) >> 1;
	if (L != R && lazyprop[indx] != 0)
	{
		repair(indx);
	}
	upd(l, r, change, L, mid, indx * 2);
	upd(l, r, change, mid + 1, R, indx * 2 + 1);
	wordTree2[indx] = wordTree2[indx * 2] + wordTree2[indx * 2 + 1];
	wordTree2[indx] %= modik;
	wordTree1[indx] = wordTree1[indx * 2] + wordTree1[indx * 2 + 1];
	wordTree1[indx] %= modik;
	return;
}
void query(int l, int r, ll &res1, ll &res2, int L, int R, int indx)
{
	if (l > R || r < L)
	{
		return;
	}
	if (L >= l && r >= R)
	{
		res1 = (res1 + wordTree1[indx]) % modik;
		res2 = (res2 + wordTree2[indx]) % modik;
		return;
	}
	if (L != R && lazyprop[indx] != 0)
	{
		repair(indx);
	}
	int mid = (L + R) >> 1;
	query(l, r, res1, res2, L, mid, indx * 2);
	query(l, r, res1, res2, mid+1, R, indx * 2+1);
	wordTree2[indx] = wordTree2[indx * 2] + wordTree2[indx * 2 + 1];
	wordTree2[indx] %= modik;
	wordTree1[indx] = wordTree1[indx * 2] + wordTree1[indx * 2 + 1];
	wordTree1[indx] %= modik;
	return;
}
void repair(int indx)
{
	lazyprop[indx * 2] = lazyprop[indx];
	lazyprop[indx * 2 + 1] = lazyprop[indx];
	wordTree1[indx * 2] = lazyprop[indx] * hashTree1[indx * 2];
	wordTree1[indx * 2 + 1] = lazyprop[indx] * hashTree1[indx * 2 + 1];
	wordTree2[indx * 2] = lazyprop[indx] * hashTree2[indx * 2];
	wordTree2[indx * 2 + 1] = lazyprop[indx] * hashTree2[indx * 2 + 1];
	wordTree1[indx * 2] %= modik;
	wordTree1[indx * 2 + 1] %= modik;
	wordTree2[indx * 2] %= modik;
	wordTree2[indx * 2 + 1] %= modik;
	lazyprop[indx] = 0;
	return;
}
