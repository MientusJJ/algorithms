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
const int maxik = 1e2+7;
const int maxN = 1 << 17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

int n, m, k;
const string d = "Draw";
const string f = "First";
const string s = "Second";
bool gD, rD, gCur, rCur;
char tab[maxik][maxik];
int dis[2], hm;
int sum = 0;
vector<int> all;
int main()
{
	es;
	gD = rD = gCur = rCur = false;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		hm = 0;
		gCur = rCur = false;
		for (int j = 1; j <= m; j++)
		{
			cin >> tab[i][j];
			if (tab[i][j] != '-')
			{
				dis[hm] = j;
				hm++;
				if (tab[i][j] == 'R')
				{
					rCur = true;
				}
				else
				{
					gCur = true;
				}
			}
			
		}
		if (hm == 2 && rCur && gCur)
		{
			if (dis[1] > dis[0]+1)
			{
				all.push_back(dis[1]-dis[0]-1);
			}
		}
		else if (hm < m)
		{
			if (gCur && !rCur)
			{
				gD = true;
			}
			else if (rCur && !gCur)
			{
				rD = true;
			}
		}
	}
	if (gD && rD)
	{
		cout << d << endl;
		return 0;
	}
	if (gD && !rD)
	{
		cout << f << endl;
		return 0;
	}
	else if (!gD && rD)
	{
		cout << s << endl;
		return 0;
	}
	for (int i = 0; i < 9; i++)
	{
		sum = 0;
		for (int j = 0; j < all.size(); j++)
		{
			sum += ((all[j] >> i) & 1);
		}
		if (sum % (k + 1))
		{
			cout << f << endl;
			return 0;
		}
	}
	cout << s << endl;
	return 0;
}
