#include <iostream>
#include <vector>
#include <queue>
const int maxik = 2e5;
using namespace std;
typedef long long ll;
vector < vector <int> > conn;
priority_queue<ll> es;

bool visited[maxik + 7];
int depth[maxik + 7];
int sizes[maxik + 7];
ll score[maxik + 7];
ll result = 0;
void DFS(int v, int parent);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k,start,end;
	cin >> n >> k;
	conn.resize(n + 1);
	for (int i = 1; i < n; i++)
	{
		cin >> start >> end;
		conn[start].push_back(end);
		conn[end].push_back(start);
	}
	DFS(1, 0);
	while (k>0)
	{
		k--;
		result += es.top();
		es.pop();
	}
	cout << result;
}
void DFS(int v, int parent)
{
	visited[v] = true;
	if (parent != 0)
	{
		depth[v] = depth[parent] + 1;
	}
	for (int i = 0; i < conn[v].size(); i++)
	{
		if (!visited[conn[v][i]])
		{
			DFS(conn[v][i], v);
		}
	}
	score[v] += depth[v];
	sizes[parent] += 1 + sizes[v];
	score[v] -= sizes[v];
	es.push(score[v]);
	return;
}
