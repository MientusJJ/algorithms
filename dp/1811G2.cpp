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
const int maxik = 5e3 + 7;
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

ll powik(ll a,ll b, ll modek = modik);

ll fac[maxik],invfac[maxik];
ll dp[maxik];
int t,n,m;
int tab[maxik];
ll freq[maxik];
ll maxSEQ{0};
ll newton(ll n, ll k);
int main()
{
    fac[0]=invfac[0]=1;
    for(int i=1;i<=5003;i++)
    {
        fac[i]= fac[i-1]*i;
        fac[i] %= modik;
        invfac[i] = invfac[i-1]*powik(i,modik-2);
        invfac[i] %= modik;
    }
    cin >> t;
    while(t--)
    {
        scanf("%d %d", &n,&m);
        mst(freq,-1);
        mst(dp,0);
        dp[0] = 1;
        freq[0] = 0;
        maxSEQ = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tab[i]);

        }
        for(int i=1;i<=n;i++)
        {
            int c{0};
            for(int j{i};j>=1;j--)
            {
                if(tab[i] == tab[j])
                {
                    c++;
                }
                if(c >= m)
                {
                    freq[i] = std::max(freq[i],freq[j-1]+1ll);      
                }
            }
            c = 0;
            maxSEQ = max(maxSEQ,freq[i]);
            for(int j{i};j>=1;j--)
            {
                if(tab[i] == tab[j])
                {
                    c++;
                }
                if(c >= m && freq[j-1] == freq[i]-1)
                {
                   dp[i] +=1ll*dp[j-1]*newton(c-1,m-1);
                   dp[i]%=modik;  
                }
            }
        }
        ll ans{0};
        for(int i{0};i<=n;i++)
        {
            if(maxSEQ ==freq[i])
            {
                ans += dp[i];
                ans %= modik;
            }
        }
        printf("%lld\n", ans);
    }
}
ll powik(ll a,ll b, ll modek)
{
    if(b == 0)
    {
        return 1ll;
    }
    if(b%2)
    {
        return (powik(a,b-1,modek)% modek * a)%modek;
    }
    else 
    {
        ll res = powik(a,b/2,modek)%modek;
        return (res*res)%modek;
    }
}
ll newton(ll n, ll k)
{
    return ((fac[n]*invfac[k])%modik *invfac[n-k])%modik;
}
