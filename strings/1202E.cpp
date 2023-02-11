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

struct bigTrie
{
    int trie[maxik][maxN];
    int leaf[maxik];
    int next[maxik];
    int ans[maxik];
    int cnt = 0;
    void insert(string str)
    {
        int root = 0;
    	for(int i=0;i<str.size();i++)
	    {
            int c = str[i] - 'a';
    		if(!trie[root][c])
    		{
                trie[root][c] = ++cnt;
    		}
            root = trie[root][c];
	    }
        leaf[root]++;
    }
    void build()
    {
        queue<int> q;
        for(int i{0};i<maxN;i++)
        {
	        if(trie[0][i])
	        {
                q.push(trie[0][i]);
	        }
        }
        while(q.size())
        {
            int u = q.front();
            q.pop();
            for(int i=0;i<maxN;i++)
            {
	            if(!trie[u][i])
	            {
                    trie[u][i] = trie[next[u]][i];
	            }
                else
                {
                    next[trie[u][i]] = trie[next[u]][i];
                    q.push(trie[u][i]);
                }
            }
            leaf[u] += leaf[next[u]];
        }
    }
    void makeAns(string s)
    {
        int j = 0;
        for(int i=0;i<s.size();i++)
        {
            j = trie[j][s[i] - 'a'];
        	ans[i] = leaf[j];
        }
    }
};
int n;
string t;
bigTrie A, B;
int main()
{
    es;
    cin >> t;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        A.insert(str);
        reverse(all(str));
        B.insert(str);
    }
    A.build();
    B.build();
    A.makeAns(t);
    reverse(all(t));
    B.makeAns(t);
    ll ans = 0;
    for(int i=0;i<t.size();i++)
    {
        ans += 1ll * A.ans[i] * B.ans[t.size() - 2 - i];
    }
    cout << ans;
    return 0;
}
