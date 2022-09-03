//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxik = 2e5;
const int two = 2;
using ll = long long;
struct vex
{
	ll cost;
	bool curr;
	bool expected;
};
ll sizes[maxik + 7];
ll result;
vex mainTab[maxik+7];
vector<vector <int> > conn;
ll toChange[maxik + 7][two];
void Counting(int v, int p);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,start,end;
	cin >> n;
	conn.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> mainTab[i].cost >> mainTab[i].curr >> mainTab[i].expected;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> start >> end;
		conn[start].push_back(end);
		conn[end].push_back(start);
	}
	Counting(1, 0);
	if (toChange[1][0] == 0 && toChange[1][1] == 0)
	{
		cout << result;
	}
	else
	{
		cout << "-1";
	}
}

void Counting(int v, int p)
{
	if (mainTab[v].curr != mainTab[v].expected)
	{
		toChange[v][int(mainTab[v].expected)]++;
	}
	for (int i = 0; i < conn[v].size(); i++)
	{
		if (conn[v][i] != p)
		{
			mainTab[conn[v][i]].cost = min(mainTab[conn[v][i]].cost, mainTab[v].cost);
			Counting(conn[v][i], v);
			toChange[v][0] += toChange[conn[v][i]][0];
			toChange[v][1] += toChange[conn[v][i]][1];
		}
	}
	int minimini = min(toChange[v][0], toChange[v][1]);
	result += ll(2 * minimini*mainTab[v].cost);
	for (int i=0; i < two; i++)
	{
		toChange[v][i] -= minimini;
	}
	return;
}
