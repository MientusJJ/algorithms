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
const int maxN = 2e6 + 7;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

map<pll, int> games;
string CD, game;
int n, k, len, m, mini;

const int hash1 = 12373;
const int hash2 = 12517;
ll hashbase1, hashbase2;
ll CDhash1[maxN], CDhash2[maxN];
set<int> s;
int made[maxN];
int main()
{
	es;
	cin >> n >> k;
	len = n * k;
	cin >> CD;
	CD = ' ' + CD;
	for (int i = 1; i < len + 1; i++)
	{
		CD += CD[i];
	}
	hashbase1 = hashbase2 = 1;
	for (int i = 1; i <= CD.size(); i++)
	{
		CDhash1[i] = CDhash1[i - 1] * hash1 + (CD[i] - 'a' + 1);
		CDhash2[i] = CDhash2[i - 1] * hash2 + (CD[i] - 'a' + 1);
		CDhash1[i] %= modik;
		CDhash2[i] %= modik;
		if (i > k)
		{
			continue;
		}
		hashbase1 = hashbase1 * hash1;
		hashbase1 %= modik;
		hashbase2 = hashbase2 * hash2;
		hashbase2 %= modik;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> game;
		pll essunia = { 0,0 };
		for (int i = 0; i < k; i++)
		{
			essunia.first = essunia.first*hash1 + (game[i] - 'a' + 1);
			essunia.first %= modik;
			essunia.second = essunia.second*hash2 + (game[i] - 'a' + 1);
			essunia.second %= modik;
		}
		games[essunia] = i;
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 1;made[j] ; j++)
		{
			made[j] = 0;
		}
		s.clear();
		mini = INF;
		for (int j = 1; j <= n; j++)
		{
			pll essunia = { 0,0 };
			essunia.first = ((CDhash1[j*k + i] - CDhash1[(j - 1)*k + i] * hashbase1 % modik) + modik) % modik;
			essunia.second = ((CDhash2[j*k + i] - CDhash2[(j - 1)*k + i] * hashbase2 % modik) + modik) % modik;
			made[j] = games[essunia];
			mini = min(mini, made[j]);
			if (s.find(made[j]) != s.end())
			{
				break;
			}
			s.insert(made[j]);
		}
		if (s.size() == n && mini)
		{
			Y;
			for (int j = 1; j <= n; j++)
			{
				cout << made[j] << " ";
			}
			return 0;
		}
	}
	N;
	return 0;
}
