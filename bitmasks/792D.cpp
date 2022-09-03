
#include <iostream>
#include <string>

using namespace std;
using ll = long long;
int n;
ll tree;
ll num, curr;
string s;
void makeU();
void makeL();
void makeR();
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> tree >> n;
	tree++;
	tree >>= 1;
	for (int i = 0; i < n; i++)
	{
		cin >> num >> s;
		for (int  i = 0; i < s.length(); i++)
		{
			if (s[i] == 'L')
			{
				makeL();
			}
			else if (s[i] == 'R')
			{
				makeR();
			}
			else
			{
				makeU();
			}
		}
		//cout << "ODP: ";
		cout << num << "\n";
	}
	
	
	return 0;
}
void makeR()
{
	ll t = (num &(-num));
	if (t & 1)
	{
		return;
	}
	num += ((num &(-num)) >> 1);
	return;
}
void makeL()
{
	ll t = (num &(-num));
	if (t & 1)
	{
		return;
	}
	num -= ((num &(-num)) >> 1);
	return;
}
void makeU()
{
	if ((num &(-num)) & tree)
	{
		return;
	}
	ll t = ((num &(-num)));
	t <<= 1;
	if (num & (t))
	{
		num -= (num &(-num));
	}
	else
	{
		num += (num &(-num));
	}
	return;
}
