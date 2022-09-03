#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
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
const int maxik = 10110;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

struct edge {
	int a;
	int b;
	int flow;
	int cap;
};
vector<int> g[maxik];
vector<edge> e;
void addEdge(int aa, int bb, int cc);
bool lF(double essa);
int n, m, x,s,t;
int A[maxik], B[maxik], C[maxik];
int bck[maxik];
ll BFS(int s, int t);
ll MfMc(int s, int t);
int main()
{
	es;
	cin >> n >> m >> x;
	s = 0;
	t = n + 1;
	for (int i = 1; i <= m; i++)
	{
		cin >> A[i] >> B[i] >> C[i];
	}
	double l = 0, r = 1e6 + 7;
	for(int i=0;i<100;i++)
	{
		double mid = (l + r)/2;
		if (lF(mid))
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	prec(10);
	cout << l * x;
	return 0;
}

void addEdge(int aa, int bb, int cc)
{
	edge e1{ aa,bb,0,cc };
	edge e2{ bb,aa,0,0 };
	g[aa].pb(e.size());
	e.pb(e1);
	g[bb].pb(e.size());
	e.pb(e2);
}
bool lF(double essa)
{
	for (int i = 1; i <= n; i++)
	{
		g[i].clear();
	}
	e.clear();
	for (int i=1; i <= m; i++)
	{
		addEdge(A[i], B[i], min(1.0*x, double(C[i]) / essa));
	}
	addEdge(s, 1, x);
	addEdge(n, t, x);
	return MfMc(s,t) == x;
}
ll MfMc(int s, int t)
{
	ll flow = 0;
	while (ll pushed = BFS(s, t))
	{
		flow += pushed;
	}
	return flow;
}
ll BFS(int s, int t)
{
	memset(bck, -1, sizeof bck);
	bck[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int id = g[v][i];
			int to = e[id].b;
			if (e[id].flow < e[id].cap && bck[to] == -1)
			{
				bck[to] = id;
				q.push(to);
			}
		}
	}
	if (bck[t] == -1) return 0;
	int u = t;
	ll flowek = INF;
	while (u != s)
	{
		flowek = min(flowek, (ll)e[bck[u]].cap - e[bck[u]].flow);
		u = e[bck[u]].a;
	}
	u = t;
	while (u != s)
	{
		e[bck[u]].flow += flowek;
		e[bck[u] ^ 1].flow += flowek;
		u = e[bck[u]].a;
	}
	return flowek;
}
