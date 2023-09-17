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


string str;
int n,m;
const string no{"NO"};
const string yes{"YES"};
set<int> s;
int main()
{
    es;
    cin >> n >> m;
    cin >> str;
    str = " " + str;
    for(int i=1;i<=n;i++)
    {
        if((i%2) && (str[i] != '('))
        {
            s.insert(i);
        }
        else if((i%2) == 0 && (str[i]!=')'))
        {
            s.insert(i);
        }
    }
    while(m--)
    {
        int a;
        cin >> a;
        if(n%2)
        {
            cout << no << "\n";
            continue;
        }
        if(s.count(a))
        {
            s.erase(a);
        }
        else s.insert(a);
        
        if(s.size() && ((*s.begin()%2) || (*s.rbegin()%2) == 0))
        {
            cout << no << "\n";
            continue;
        }
        cout << yes << "\n";

    }
    return 0;
     
}
