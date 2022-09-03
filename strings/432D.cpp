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
using pii = pair<int, int>;
const int maxik = 1e5 + 7;
const int maxN = 1 << 14;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

int hop[maxik];
int n;
int hm[maxik], prefsufsum[maxik];
int counter = 0;
int main()
{
	es;
	string s;
	cin >> s;
	s = " " + s;
	int i, j;
	i = 0;
	j = 2;
	n = s.size();
	for (j; j < n; j++)
	{
		while (i && s[i+1]!=s[j])
		{
			i = hop[i];
		}
		if (s[i + 1] == s[j])
		{ 
			i++;
		}
		hop[j] = i;
	}
	
	for (i = n-1;i ;i = hop[i])
	{
		hm[++counter] = i;
	}
	cout << counter << "\n";
	for (i = n; i; i--)
	{
		prefsufsum[hop[i]] += ++prefsufsum[i];
	}
	for (int i = counter; i; i--)
	{
		cout << hm[i] << " " << prefsufsum[hm[i]] << "\n";
	}
	return 0;
}
 
