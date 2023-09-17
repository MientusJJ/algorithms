#include <bits/stdc++.h>
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
const int maxik = 5e2 + 7;
const int maxN = 20;
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

int n;
std::array<std::array<int,maxik>,maxik> dp,tab;
int main()
{
    es;
    cin >> n;
    for(int i{1};i<=n; i++)
    {
        cin >> tab[i][i];
        dp[i][i]=1; 
    }
    for(int len{1};len<n;len++)
    {
        for(int l=1;l<=n;l++)
        {
            int r = l+len;
            if(r>n) break;
            dp[l][r] = INF;
            for(int k=l;k<r;k++)
            {
                dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]);
                if(dp[l][k] == 1 && dp[k+1][r] == 1  && tab[l][k] == tab[k+1][r])
                {
                    dp[l][r] = 1;
                    tab[l][r] = 1 + tab[k+1][r];
                } 
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
