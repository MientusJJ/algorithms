#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;
const int maxik = 1007;
const string  a = "ATK";
const string  d = "DEF";
int jiroA[maxik], jiroD[maxik], ciel[maxik];
int n,m;
bool f;
int jA, jD;
int val;
string s;
int ansAtt;
int ansWh;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	f = false;
	jA = jD = val = ansAtt = ansWh = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s >> val;
		if (s == a)
		{
			jiroA[jA++]=val;
		}
		else
		{
			jiroD[jD++]=val;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> ciel[i];
	}
	
	sort(jiroA, jiroA+jA);
	sort(jiroD, jiroD+jD);
	sort(ciel, ciel+m);
	for (int i = 0, j = m - 1; j >= 0, i < jA; i++, j--)
	{
		if (ciel[j]<=jiroA[i])
		{
			break;
		}
		ansAtt += ciel[j] - jiroA[i];
	}
	int i=0, j=0;
	for (int k = 0; k < m; k++)
	{
		if (i<jD && ciel[k]>jiroD[i])
		{
			i++;
		}
		else if (j < jA && ciel[k] >= jiroA[j])
		{
			ansWh += ciel[k] - jiroA[j];
			j++;
		}
		else
		{
			ansWh += ciel[k];
		}
		if ((j+i)==n)
		{
			f = true;
		}
	}
	if (f)
	{
		cout << max(ansAtt, ansWh);
	}
	else
	{
		cout << ansAtt;
	}
	return 0;
}
