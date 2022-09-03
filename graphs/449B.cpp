#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int maxik = 1e5 + 1;
const int modik = 1e9 + 7;
const ll INF = 1e17;

int n, m, k;
ll dis[maxik];
priority_queue<pair<pair<long long,int>,bool> > q;
vector <vector<pii> >  conn;
bool vis[maxik];
int ans = 0;
void Dij(int v);
int main()
{
	es;
	cin >> n >> m >> k;
	conn.rs(n + 1);
	for (int i = 2; i <= n; i++)
	{
		dis[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b,w;
		cin >> a >> b >> w;
		conn[b].pb( {w,a} );
		conn[a].pb( {w,b} );
	}
	for (int i = 0; i < k; i++)
	{
		int a, w;
		cin >> a >> w;
		q.push({ {-w,a},false });
	}
	Dij(1);
	cout << ans << "\n";
	return 0;
}
void Dij(int v)
{
	
	q.push({ { 0,1 },true });
	while (!q.empty())
	{
		ll wage = -q.top().first.first;
		int u = q.top().first.second;
		bool train = q.top().second;
		q.pop();
			
			if (!train)
			{
				if (dis[u] <= wage)
				{
					++ans;
				}
				else
				{
					dis[u] = wage;
				}
			}
			if(vis[u])
			{
				continue;
			}
			vis[u] = true;
			for (int i = 0; i < conn[u].size(); i++)
			{
				if (1LL*wage +conn[u][i].first<dis[conn[u][i].second])
				{
					dis[conn[u][i].second] = 1LL * wage + conn[u][i].first;
					q.push({ {-dis[conn[u][i].second],conn[u][i].second},true });
				}
			}
		
	}
	return;
}
