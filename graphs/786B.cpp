#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <string>
#include <cmath>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#define es ios::sync_with_stdio(false);cin.tie(0);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define Y cout << "YES" << "\n";
#define N cout << "NO" << "\n";
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxik = 1e5 + 7;
const int maxN = 1<<17;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;

struct node
{
	ll price=0;
	int b=0;
	
	node()
	{
		price = b = 0;
	}
	node(ll aa, int bb)
	{
		price = aa;
		b = bb;
	}
};

struct compadre {
	bool operator()(const pll &a, const pll &b)
	{
		return a.second > b.second;
	}
};
ll ans[int(7e5)];
bool vis[int(7e5)];
vector<int> g[int(7e5)];
int sTree[maxN * 2][2];
int n, q,s,id;
vector<node> e;
void build(int kind,int indx=1,int l=1,int right=maxN);
priority_queue<pll, vector<pll>, compadre> pq;
void addEdge(int a, int b, int w);
void newEgde(int v, int l, int r, ll w, int kind, int indx = 1, int L = 1, int R = maxN);
int main()
{
	es;
	memset(ans, -1, sizeof ans);
	cin >> n >> q >> s;
	id = n;
	build(0);
	build(1);
	while (q--)
	{
		char c;
		cin >> c;
		if (c == '1')
		{
			int u, v;
			ll w;
			cin >> v >> u >> w;
			addEdge(v, u, w);
			
		}
		else if (c == '2')
		{
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			newEgde(v, l, r, w, 0);
		}
		else
		{
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			newEgde(v, l, r, w, 1);
		}
	}
	pq.push(make_pair(s, 0));
	while (pq.size())
	{
		auto t = pq.top();
		pq.pop();
		if (vis[t.first])
		{
			continue;
		}
		vis[t.first] = 1;
		ans[t.first] = t.second;
		for (int i = 0; i < g[t.first].size(); i++)
		{
			auto indx = g[t.first][i];
			int u = e[indx].b;
			ll val = e[indx].price;
			pq.push({ u,val + t.second });
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
void build(int kind, int indx , int l , int r)
{
	sTree[indx][kind] = ++id;
	if (!kind)
	{
		for (int i = l; i <= r; i++)
		{
			addEdge(sTree[indx][kind], i, 0);
		}
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			addEdge(i,sTree[indx][kind], 0);
		}
	}
	if (l == r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	build(kind, indx * 2, l, mid);
	build(kind, indx * 2+1, mid+1, r);
	return;
}
void addEdge(int a, int b, int w)
{
	g[a].push_back(e.size());
	node p(w, b);
	e.push_back(p);
	return;
}
void newEgde(int v, int l, int r, ll w,int kind, int indx, int L, int R)
{
	if (l > R || R < L || r < L)
	{
		return;
	}
	if (l <= L && r >= R)
	{
		if (!kind)
		{
			addEdge(v, sTree[indx][kind], w);
		}
		else
		{
			addEdge(sTree[indx][kind],v, w);
		}
		return;
	}
	int mid = (L + R) >> 1;
	newEgde(v, l, r, w, kind, indx * 2, L, mid);
	newEgde(v, l, r, w, kind, indx * 2+1,mid+1,R);
	return;
}
