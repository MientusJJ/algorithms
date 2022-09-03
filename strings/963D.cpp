#include<bits/stdc++.h>
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
const int maxN = 1e1;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;


bitset<maxik>b[27], word;
string s, t;
int main()
{
	es;
	int n, m;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
	{
		b[s[i] - 'a' + 1][i] = 1;
	}
	int q;
	cin >> q;
	while (q--)
	{
		int num;
		cin >> num;
		cin >> t;
		word.set();
		m = t.size();
		for (int i = 0; i < m; i++)
		{
			word &= b[t[i] + 1 - 'a'] >> i;
		}
		int k = word.count();
		if (k < num)
		{
			cout << "-1";
		}
		else 
		{
			int ans = INF;
			vector<int> v;
			for (int i =word._Find_first(); i < n; i=word._Find_next(i))
			{
					v.push_back(i);
			}
			for (int i = 0; i+num-1 < v.size(); i++)
			{
				ans = min(ans, v[i + num - 1] - v[i]);
			}
			ans += m;
			cout << ans;
		}
		cout << "\n";
	}
	return 0;
}
