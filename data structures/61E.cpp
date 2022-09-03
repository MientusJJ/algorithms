#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using parka = pair<int, int>;
const int maxik = 1 << 20;
int checkTree(int leftRange,int rightRange, int left = 1, int right=maxik, int indx=1);
void upTree(int indx);
vector<parka> v;
ll result = 0;
int tab[maxik];
int minimini[maxik];
int sTree[maxik*2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	int sc = 0;
	int p = -1;
	for (int i = 1; i <= n; i++)
	{
		if (v[i].first != p)
		{
			sc++;
		}
		tab[v[i].second] = sc;
		p = v[i].first;
	}
	for (int i = 1; i <= n; i++)
	{
		minimini[i] = checkTree(tab[i] + 1, maxik);
		upTree(tab[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		int t = checkTree(1, tab[i] - 1);
		result += ((ll)minimini[i] * (ll)(t - (i - 1 - minimini[i])));
	}
	cout << result;
	//system("pause");
}
void upTree(int indx)
{
	indx += maxik - 1;
	sTree[indx]++;
	while (indx != 1)
	{
		indx /= 2;
		sTree[indx] = sTree[2 * indx] + sTree[(2 * indx) + 1];
	}
	return;
}
int checkTree(int leftRange, int rightRange, int left, int right, int indx)
{
	if (rightRange<left || right<left || leftRange > right)
	{
		return 0;
	}
	if (left >= leftRange && right <= rightRange)
	{
		return sTree[indx];
	}
	int mid = (left + right) / 2;
	return checkTree(leftRange, rightRange, left, mid, indx * 2) + checkTree(leftRange, rightRange, mid + 1, right, (indx * 2) + 1);
}
