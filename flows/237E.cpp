#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f

using namespace std;
const int maxik = 1010;
const int letters = 26;
int bck[maxik];
int bigCost[maxik];
struct edge
{
	int cost;
	int u, v;
	int flow;
	int cap;
	edge()
	{
		u = v = cost = cap = flow = 0;
	}
	edge(int U, int V, int c, int f, int ca)
	{
		u = U;
		v = V;
		cost=c;
		flow=f;
		cap = ca;	
	}
};
vector<edge> strings;
vector<vector<int>> conn;
int source[letters+1];
int lettersfromstrings[maxik][letters+1];
int toUse[maxik];

int ans = 0;
string str ="";
int n;
int sum = 0;
int wholeFlow = 0;
void addEdge(int u, int v, int c, int ca);
bool BFS(int s, int t);
void flow(int s, int t);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	cin >> n;
	conn.resize(maxik);
	sum = str.size();
	for (int i = 0; i < str.size(); i++)
	{
		source[str[i] - 'a' + 1]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> str >> toUse[i];
		for (int j = 0; j < str.size(); j++)
		{
			lettersfromstrings[i][str[j] - 'a' + 1]++;
		}
	}
	int s = 0;
	int t = 26 + 1 + n;
	for (int i = 1; i <= 26; i++)
	{
		if (!source[i])
		{
			continue;
		}
		addEdge(s, i, 0, source[i]);
		for (int j = 1; j <= n; j++)
		{
			if (!(lettersfromstrings[j][i]))
			{
				continue;
			}
			addEdge(i, letters + j, j, lettersfromstrings[j][i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		addEdge(letters + i, t, 0, toUse[i]);
	}
	flow(s, t);
	if (wholeFlow != sum)
	{
		cout << "-1";
	}
	else
	{
		cout << ans;
	}
	return 0;
}
void addEdge(int U, int V, int c, int ca)
{
	edge e1(U, V, c, 0, ca);
	edge e2(V,U,-c,0,0);
	conn[U].push_back(strings.size());
	strings.push_back(e1);
	conn[V].push_back(strings.size());
	strings.push_back(e2);
	return ;
}
bool BFS(int s, int t)
{
	memset(bck, -1, sizeof(bck));
	memset(bigCost, INF, sizeof(bigCost));
	queue<int> es;
	es.push(s);
	bck[s] = 0;
	bigCost[s] = 0;
	while (!es.empty())
	{
		int u = es.front();
		es.pop();
		for (int i = 0; i < conn[u].size(); i++)
		{
			int id = conn[u][i];
			edge curr = strings[id];
			if (curr.cap > curr.flow && bigCost[curr.v] > bigCost[u] + curr.cost)
			{
				bigCost[curr.v] = bigCost[u] + curr.cost;
				bck[curr.v] = id;
				es.push(curr.v);
			
			}
		}

	}
	return bck[t] != -1;
}
void flow(int s, int t)
{
	while (BFS(s,t))
	{
		int Min = INF;
		int u = t;
		while (u != s)
		{
			edge e = strings[bck[u]];
			Min = min(Min, e.cap - e.flow);
			u = e.u;
		}
		u = t;
		while (u != s)
		{
			strings[bck[u]].flow += Min;
			strings[bck[u] ^ 1].flow -= Min;
			ans += strings[bck[u]].cost * Min;
			u = strings[bck[u]].u;
		}
		wholeFlow += Min;
	}
}
