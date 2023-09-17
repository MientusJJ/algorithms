#include <bits/stdc++.h>

using namespace std;

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
const int maxik = 1e2 + 7;
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


string s;
ll n;
ll dp[maxik][2];
void iteration(int k);
ll result{0};
int main()
{
    cin >> s;
    n = s.size();
    iteration(0);
    iteration(1);
    cout << result;
}
void iteration(int k)
{
    mst(dp,0);
    dp[0][k] = 1;
    for(int i{1};i<n;i++)
    {
        if(s[i]=='A')
        {
            if(s[i-1]=='A')
            {
                dp[i][0] = dp[i-1][0]+dp[i-1][1];
            }
            else
            {
                dp[i][1] = dp[i-1][1];
                dp[i][0] = dp[i-1][0];
            }
        }
        else
        {
            if(s[i-1]=='A')
            {
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0]+dp[i-1][1];
            }
            else
            {
                dp[i][1] = dp[i-1][0];
                dp[i][0] = dp[i-1][0];
            }
        }
    }
    if(!k)
    {
        if(s[0]=='A')
        {
            if(s[n-1]=='A')
            {
                result+=dp[n-1][0]+dp[n-1][1];
            }
            else
            {
                result += dp[n-1][0];
            }

        }
        else
        {
            if(s[n-1]=='A')
            {
                result += dp[n-1][1];
            }
            else
            {
                result += dp[n-1][0];
            }
 
        }
    }
    else
    {
        if(s[0]=='A')
        {
            if(s[n-1]=='B')
            {
                result+=dp[n-1][1];
            }

        }
        else
        {
            if(s[n-1]=='A')
            {
                result += dp[n-1][1]+dp[n-1][0];
            }
            else
            {
                result += dp[n-1][0];
            }
 
        }
    }

}

