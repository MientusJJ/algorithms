#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <string>
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
using pii = pair<int, int>;
const int maxik = 1e6 + 7;
const int maxN = 2e5 + 7;
const int INF = 0x3f3f3f3f;
const ll INFll = (1LL << 60);
const int modik = 1e9 + 7;
vector<int> que, endik;
vector < vector<int> > g;
ll ans = 0;
int n;
int p;
int conn[maxN];
bool visited[maxN];
ll tab[maxN];
queue<int> q;
int main()
{
	cin >> n;
	g.rs(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		if (p != -1)
		{
			g[i].pb(p);
			conn[p]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (conn[i] == 0)
		{
			q.push(i);
			visited[i] == true;
		}
	}
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i];
			conn[u]--;
			if (!visited[u] && conn[u] == 0)
			{
				q.push(u);
				visited[u] == true;
			}
		}
		que.pb(v);
	}
	for (int i = 0; i < que.size(); i++)
	{
		int v = que[i];
		ans += tab[v];
		if (tab[v] > 0)
		{
			for (int i = 0; i < g[v].size(); i++)
			{
				tab[g[v][i]] += tab[v];
			}
			endik.pb(v);
		}
	}
	for (int i = que.size()-1; i>=0 ; i--)
	{
		if (tab[que[i]] <= 0)
		{
			endik.pb(que[i]);
		}
	}
	cout << ans << "\n";
	for (int i=0; i < endik.size(); i++)
	{
		cout << endik[i] << " ";
	}
	return 0;
}
