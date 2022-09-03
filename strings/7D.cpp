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
const int maxik = 5e6 + 7;
const int maxN = 1 << 14;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

const int p1 = 127;
const int p2 = 131;
ll ans = 0;
ll first=0, second=0,firstReverse=0,secondReverse=0;
ll counter1=1, counter2=1;
string s;
ll dp[maxik];
int main()
{
	es;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i < s.size(); i++)
	{
		firstReverse = firstReverse * p1 + s[i];
		firstReverse %= modik;
		first = counter1 * s[i] + first;
		first %= modik;
		counter1 *= p1;
		counter1 %= modik;
		secondReverse = secondReverse * p2 + s[i];
		secondReverse %= modik;
		second = counter2 * s[i] + second;
		second %= modik;
		counter2 *= p2;
		counter2 %= modik;
		if (first == firstReverse && second == secondReverse)
		{
			dp[i] += dp[i / 2] + 1;
		}
		ans += dp[i];
	}
	cout << ans;
	return 0;
}
