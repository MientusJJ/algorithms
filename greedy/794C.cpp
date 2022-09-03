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
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 1e5 + 7;
const int maxN = 1010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

string s1, s2,out;

int main()
{
	cin >> s1 >> s2;
	int begin = 0, end = s1.size() - 1;
	int s1start = 0; int s1end = (s1.size()-1) / 2;
	int s2start = (s2.size()+1) / 2; int s2end = s1.size() - 1;
	out.resize(s1.size());
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	int n =(out.size()/2)*2;
	for (int i = 0; i < n; i++)
	{
		if (i%2==0)
		{
			if (s1[s1start] < s2[s2end])
			{
				out[begin++] = s1[s1start++];
			}
			else
			{
				out[end--] = s1[s1end--];
			}
		}
		else
		{
			if (s1[s1start] < s2[s2end])
			{
				out[begin++] = s2[s2end--];
			}
			else
			{
				out[end--] = s2[s2start++];
			}
		}
	}
	if (s1.size() & 1)
	{
		for (int i = 0; i <= n; i++)
		{
			if (!out[i])
			{
				out[i] = s1[s1start];
				break;
			}
		}
	}
	cout << out;
	return 0;
}
