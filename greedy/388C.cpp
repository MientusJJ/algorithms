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
#define es ios::sync_with_stdio(false);cin.tie(0);
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define rs resize
#define rsv reserve
#define eb emplace_back
#define prec(i) cout << std::fixed << std::setprecision(i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxik = 1e5 + 7;
const int maxN = 1010;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;

priority_queue<int> q;
int n,k;
int v;
int A, B;
int main()
{
	es;
	A = B=0;
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cin >> k;
		for (int j = 1; j <= (k >> 1); j++)
		{
			cin >> v;
			A += v;
		}
		if (k & 1)
		{
			cin >> v;
			q.push(v);
		}
		for (int j = 1; j <= (k >> 1); j++)
		{
			cin >> v;
			B += v;
		}
	}
	while (!q.empty())
	{
		A += q.top();
		q.pop();
		if (!q.empty())
		{
			B += q.top();
			q.pop();
		}
	}
	cout << A << " " << B;
	return 0;
}
