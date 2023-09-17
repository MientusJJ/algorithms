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
const int maxik = 2e5 + 7;
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


array<int,maxik> tab;
int n,k;
int l{1},r,mid;
bool check(int x)
{
    vector<int> pref(n+1),val(n+1),minim(n+1);
    for(int i = 1;i <= n;i++)
    {
        if(tab[i] >= x) val[i] = 1;
        else val[i] = -1;
    }
    for(int i={1};i <= n;i++)
    {
        pref[i] = pref[i-1] + val[i];
        minim[i] = min(minim[i-1],pref[i]);
    }
    for(int i = k;i<=n;i++)
    {
        if(pref[i] - minim[i-k] > 0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d %d", &n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tab.at(i));
    }
    r = n;
    while(l<=r)
    {
        mid = (r+l) / 2;
        if(check(mid))
        {
            l = mid + 1;
        }
        else r = mid - 1;

    }
    printf("%d\n",l-1);
}
