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


ll indx{0};
ll bank{0};
ll result{0};
int main()
{
    es;
    ll n,p,m;
    cin >> n >> p >> m;
    ll day, amount;
    for(int i{0};i < n; i++)
    {
        cin >> day >> amount;
        ll daysToNegative = abs(bank)/p + 1;
        if(bank < 0) daysToNegative=1;
        if(day - indx > daysToNegative)
        {
            result++;
        }
        bank -= p*(day-indx-1);
        indx= min(indx+daysToNegative+1,ll(day));
        result += day - indx;
        bank+=(-p+amount);
        if(bank<0) result++;
        indx = day;       
    }
    ll daysToNegative = abs(bank)/p + 1;
      if(bank < 0) daysToNegative=1;
    if(m + 1 - indx > daysToNegative)
    {
            result++;
    }
    indx= min(indx+daysToNegative,ll(m));
    result += m - indx;
    cout << result;
}
