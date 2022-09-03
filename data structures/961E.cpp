#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using parka = pair<int, int>;
const int maxik= (1 << 18);
vector<int >  sTree[maxik * 2];
int tab[maxik];
void tree(int LL=1, int RR=maxik, int indx=1);
void checkTree(int LL, int RR, int indx = 1, int l=1, int r=maxik);
ll result = 0;
vector<parka> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tab[i];
		tab[i] = min(tab[i], n);
		sTree[-1 + maxik + i].push_back(tab[i]);
	}
	tree();
	for (int i = 1; i <= n; i++)
	{
		checkTree(i + 1, tab[i]);
	}

	cout << result;
	//system("pause");
}
void tree(int LL, int RR, int indx)
{
	if (LL == RR) return;
	int mid = LL + RR;
	mid /= 2;
	tree(LL, mid, indx * 2);
	tree(mid + 1, RR, indx * 2 + 1);
	for (int i = 0; i < sTree[indx * 2].size(); i++)
	{
		sTree[indx].push_back(sTree[indx * 2][i]);
	}
	for (int i = 0; i < sTree[indx * 2+1].size(); i++)
	{
		sTree[indx].push_back(sTree[indx * 2+1][i]);
	}
	sort(sTree[indx].begin(), sTree[indx].end());
	return;
}
void checkTree(int LL, int RR, int indx , int l , int r)
{
	if (LL > RR || r<l || l>RR || r < LL)
	{
		return;
	}
	if (l >= LL && r <= RR)
	{
		result += (sTree[indx].size() - (lower_bound(sTree[indx].begin(), sTree[indx].end(), LL - 1) - sTree[indx].begin()));
		return;
	}
	int mid = l + r;
	mid /= 2;
	checkTree(LL, RR, indx * 2, l, mid);
	checkTree(LL, RR, indx * 2+1, mid+1, r);
	return;
}
