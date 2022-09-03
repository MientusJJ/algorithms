#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using parka = pair<int, int>;
const  int maxik=(1 << 18);
vector<vector <int > > conn;
int sTree[maxik * 2][2];
int value[maxik];
int depth[maxik];
parka Timer[maxik];
int parity[maxik];
int timer = 1;
int sum = 0;
void DFS(int v, int p);
void upTree(int lRange, int rRange, int val, int x, int left = 1, int right = maxik, int indx = 1);
void answer(int x,int xStart, int left = 1, int right = maxik, int indx = 1);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m,start,end;
	char c;
	int val, x;
	cin >> n >> m;
	conn.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> value[i];
	}
	for (int i = 1; i < n; i++)
	{
		cin >> start >> end;
		conn[start].push_back(end);
		conn[end].push_back(start);
	}
	DFS(1, 0);
	for (int i = 1; i <= n; i++)
	{
		parity[i] = depth[i] % 2;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> c;
		if (c == '1')
		{
			cin >> x >> val;
			upTree(Timer[x].first, Timer[x].second, val, x);
		}
		else
		{
			cin >> x;
			sum = 0;
			answer(x, Timer[x].first);
			cout << sum + value[x] << "\n";
		}
	}
	//system("pause");
}
void DFS(int v, int p)
{
	Timer[v].first = timer;
	for (int i = 0; i < conn[v].size(); i++)
	{
		if (conn[v][i] != p)
		{
			++timer;
			depth[conn[v][i]] = depth[v] + 1;
			DFS(conn[v][i], v);
		}
	}
	Timer[v].second = timer;
}
void upTree(int lRange, int rRange, int val,int x, int left, int right, int indx)
{
	if (left > rRange || right < lRange || right <left)
	{
		return;
	}
	if (left >= lRange && right <= rRange)
	{
		sTree[indx][parity[x]] += val;
		sTree[indx][parity[x] ^ 1] -= val;
		return;
	}
	upTree(lRange, rRange, val, x, left, (left + right) / 2, 2 * indx);
	upTree(lRange, rRange, val, x, ((left + right) / 2)+1,right , (2 * indx)+1);
	return;
}
void answer(int x, int xStart, int left , int right, int indx)
{
	sum += sTree[indx][parity[x]];
	if (left == right)
	{
		return;
	}
	else
	{
		if (xStart <= (left + right) / 2)
		{
			answer(x, xStart, left, (left + right) / 2, 2 * indx);
		}
		else
		{
			answer(x, xStart, ((left + right) / 2)+1,right, (2 * indx)+1);
		}
	}
	return;
}
