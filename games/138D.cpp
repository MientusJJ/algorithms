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
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
#define TXT  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxik = 4e1 + 7;
const int maxN = 1 << 20;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;

int grundy[maxik][maxik][maxik][maxik][tight];
char board[maxik][maxik];
int n, m;
int dfs(int flag, int minX=1, int maxX=m+n, int minY=1, int maxY=m+n);
int main()
{
	es;
	//TXT;
	memset(grundy, -1, sizeof grundy);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}
	}
	int ans = dfs(1)^dfs(0);
	if (ans)
	{
		cout << "WIN\n";
	}
	else
	{
		cout << "LOSE\n";
	}
	return 0;
}
int dfs(int flag, int minX, int maxX, int minY, int maxY)
{
	int val = grundy[minX][maxX][minY][maxY][flag];
	if (val != -1)
	{
		return val;
	}
	else
	{
		val = 0;
	}
	set<int> mex;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (((i + j) & 1) == flag)
			{
				int x = i + j;
				int y = m - j + i;
				if (x >= minX && x <= maxX && y >= minY && y <= maxY)
				{
					if (board[i][j] == 'L')
					{
						mex.insert(dfs(flag, x + 1, maxX, minY, maxY) ^ dfs(flag, minX, x - 1, minY, maxY));
					}
					else if (board[i][j] == 'R')
					{
						mex.insert(dfs(flag,minX, maxX, minY, y-1) ^ dfs(flag, minX, maxX, y+1, maxY));
					}
					else if(board[i][j]=='X')
					{
						mex.insert(dfs(flag, minX, x-1, minY, y - 1) ^ dfs(flag, x+1, maxX, minY, y-1)^ dfs(flag, minX, x-1, y + 1, maxY)^dfs(flag, x+1, maxX, y + 1, maxY));
					}
				}
			}
		}
	}
	while (mex.count(val))
	{
		val++;
	}
	return grundy[minX][maxX][minY][maxY][flag]=val;
}
