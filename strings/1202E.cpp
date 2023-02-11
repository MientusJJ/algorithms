#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define DEBUG


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
#include <chrono>
#include <random>
#include <fstream>
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define randomizer mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define mst(v,k) memset((v),(k),sizeof(v));


using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 2e5 + 7;
const int maxN = 27;
const int INF = 0x3f3f3f3f;
const ll INFll = 1e18;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;
const int generatorModik2 = 3;
const double PI = acos(-1.);
#ifdef DEBUG
fstream in("C:/Temp/input.txt", ios::in);
fstream out("C:/Temp/output.txt", ios::out | ios::trunc);
#define cin in
#define cout out
#endif // DEBUG 

struct trie
{
	int tab[maxN];
	int cnt = 0;
};
trie mTrie[maxik][2];
void prefix(const string& str, int p, int k);
int n;
string t;
vector <string> s;
int sqrtik,cnt;
int sum[2][maxik];
int v[maxik * 2];
int check(int pos,int k, string str = t);
int main()
{
	es;
	cin >> t;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin >> str;
		s.push_back(str);
	}
	for(int k=0;k<2;k++)
	{
		cnt = 1;
		for(int i=0;i<n;i++)
		{
			if(s[i].size()>sqrt(t.size())+1)
			{
				prefix(" " + s[i] + "#" + t+"@",s[i].size(),k);
			}
			else
			{
				int root = 1;
				for(int j=0;j<s[i].size();j++)
				{
					if(!mTrie[root][k].tab[s[i][j] - 'a'])
					{
						mTrie[root][k].tab[s[i][j] - 'a'] = ++cnt;
					}
					root = mTrie[root][k].tab[s[i][j] - 'a'];
					if (j + 1 == s[i].size())
					{
						mTrie[root][k].cnt++;
						break;
					}
				}
			}
		}
		for(int i=0;i<t.size();i++)
		{
			sum[k][i] += check(i,k);
		}
		reverse(all(t));
		for(int i=0;i<n;i++)
		{
			reverse(all(s[i]));
		}

	}
	ll ans = 0;
	for(int i=0;i<t.size();i++)
	{
		ans += 1ll * sum[0][i] * sum[1][t.size() - i];
	}
	cout << ans;
	return 0;
}
void prefix(const string& str, int p, int k)
{
	v[0] = v[1] = 0;
	for(int i=2;i<str.size();i++)
	{
		int pref = v[i - 1];
		while(pref && str[pref+1]!=str[i])
		{
			pref = v[pref];
		}
		if(str[pref+1]==str[i])
		{
			pref++;
		}
		v[i] = pref;
		if(v[i]>=p)
		{
			sum[k][i - 1 - p]++;
		}
	}
	return;
}
int check(int pos,int k, string str)
{
	int root = 1;
	int ans = 0;
	while (pos <= str.size())
	{
		int c = str[pos] - 'a';
		ans += mTrie[root][k].cnt;
		if(!mTrie[root][k].tab[c])
		{
			break;
		}
		root = mTrie[root][k].tab[c];
		pos++;
	}
	return ans;
}
