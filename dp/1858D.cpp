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
const int maxik = 3e3 + 7;
const int maxN = 64;
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

int t,k,n;
ll ans[maxik];
char tree[maxik];
int pref[maxik][maxik];
int suf[maxik][maxik];
int main()
{
    es;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        scanf("%s", tree+1);
        for(int i=0;i<=n+1;i++)
        {
            for(int j = 0;j <= k;j++)
            {
                suf[i][j] = pref[i][j] = 0;
            }
        }
        
        mst(ans,-1);
        for(int r{1};r<=n;r++)
        {
            for(int l{r},cnt{0};l;l--)
            {
                if(tree[l]=='0')
                {
                    cnt++;
                }
                pref[r][cnt] = max(pref[r][cnt],r-l+1);
            }
        }
        for(int r{n};r;r--)
        {
            for(int l{r},cnt{0};l<=n;l++)
            {
                if(tree[l]=='0')
                {
                    cnt++;
                }
                suf[r][cnt] = max(suf[r][cnt],l-r+1);
            }
        }
        for(int i={n};i;i--)
        {
            for(int cnt{0};cnt<=k;cnt++)
            {
                suf[i][cnt]=max(suf[i][cnt],suf[i+1][cnt]);
                if(cnt)
                {
                     suf[i][cnt]=max(suf[i][cnt],suf[i][cnt-1]);
                }
            }
        }
        for(int i={1};i<=n;i++)
        {
            for(int cnt{0};cnt<=k;cnt++)
            {
                pref[i][cnt]=max(pref[i][cnt],pref[i-1][cnt]);
                if(cnt)
                {
                     pref[i][cnt]=max(pref[i][cnt],pref[i][cnt-1]);
                }
            }
        }
        ans[0]= pref[n][k];
        for(int i=1;i<=n;i++)
        {
            for(int j=i,cnt = 0;j<=n;j++)
            {
                if(tree[j]=='1')
                {
                    cnt++;
                }
                if(cnt > k)
                {
                    break;
                }
               ans[j-i+1]=max(ans[j-i+1],max(ll(pref[i-1][k-cnt]),ll(suf[j+1][k-cnt]))); 
            }
        }
        for(int a=1;a<=n;a++)
        {
            int res{0};
            for(int i=0;i<=n;i++)
            {
                if(ans[i]<0) continue;
                res = max(res,int(a*i+ans[i]));
            }
            printf("%d ",res);
        }
        printf("\n");
    }
}
