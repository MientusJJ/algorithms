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
const int maxik = 5e2 + 7;
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

int t,n;
int tab[maxik];
int dp[maxik][maxik];
int main()
{
    es;
    scanf("%d",&t);
    while(t--)
    {
        dp[0][0] = 0;
        scanf("%d",&n);
        mst(tab,0);
        tab[n+1]=INF;
        for(int i=1;i<=n;i++)
        {

            scanf("%d",&tab[i]);

        }
        for(int i = 1;i<=n+1;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=INF;
                if(tab[i] > tab[i-1])
                { 
                    dp[i][j] = dp[i-1][j];
                }
                if(j)
                {
                    for(int k=0;k<i;k++)
                    {
                        if(tab[i] > tab[k])
                        {
                            dp[i][j] = std::min(dp[i][j],dp[k][j-1]+i-k-1);
                            
                        }
                    }
                }

            }
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d ",dp[n+1][i]);
        }
        printf("\n");
    }
}
