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
const int maxik = 2e6 + 7;
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

int tab[maxik];
int n;
int res{0};
int main()
{
    es;
    scanf("%d", &n);
    for(int i{0}; i < n; i++)
    {
        int a;
        scanf("%d",&a);
        tab[a] = a;
    }
    for(int i = 1;i<maxik;i++)
    {
        tab[i] = max(tab[i],tab[i-1]);
    }
    for(int i{2};i<maxik;i++)
    {
        if(tab[i] == i)
        {
            for(int num{i*2};num<maxik;num+=i)
            {
                res = max(res,tab[num-1]%tab[i]);
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
