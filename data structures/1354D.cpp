#include <iostream>
#define es cin.tie(0);ios::sync_with_stdio(false);
using namespace std;
const int maxik = 1 << 20;

int tab[maxik * 2];
void build(int indx = 1, int l = 1, int r = maxik)
{
	if (r <= l)
	{
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * indx, l, mid);
	build(2 * indx + 1, mid + 1, r);
	tab[indx] = tab[indx * 2] + tab[indx * 2 + 1];
	return;
}
void upd(int number)
{
	int indx = number + maxik - 1;
	tab[indx]++;
	while (indx != 1)
	{
		indx /= 2;
		tab[indx]++;
	}
	return;
}
void del(int number, int l=1, int r=maxik, int indx=1)
{
	if (r < l) return;
	if (l == r)
	{
		tab[indx]--;
		return;
	}
	int mid = (l + r) >> 1;
	if (number > tab[indx * 2]) del(number - tab[indx * 2], mid + 1, r, indx * 2 + 1);
	else del(number, l, mid, indx * 2);
	tab[indx]--;
	return;
}
void show(int indx=1, int l=1, int r=maxik)
{
	if (l == r)
	{
		cout << indx+1-maxik;
		return;
	}
	int mid = (l + r) >> 1;
	if (tab[indx * 2])
	{
		show(indx * 2, l, mid);
	}
	else if (tab[indx * 2 + 1])
	{
		show(indx * 2+1,mid+1,r);
	}
	return;
}
int main()
{
	es;
	int n;
	int q;
	int l;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> l;
		tab[l + maxik - 1]++;
	}
	build();
	for (int i = 0; i < q; i++)
	{
		cin >> l;
		if (l > 0)
		{
			upd(l);
		}
		else
		{
			del(-l);
		}
	}
	if (tab[1])
	{
		show();
	}
	else
	{
		cout << "0";
	}
}
