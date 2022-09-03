#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	ll p = (n * 2 * m);
	if (p % k)
	{
		cout << "NO";
	}
	else
	{
		ll nn = n;
		ll mm = m;
		ll gd = gcd(mm, k);
		mm /= gd;
		k /= gd;
		gd = gcd(nn, k);
		k /= gd;
		nn /= gd;
		if (nn * 2 <= n)
		{
			nn *= 2;
		}
		else if(mm*2<=m)
		{
			mm *= 2;
		}
		gd = gcd(mm, k);
		mm /= gd;
		k /= gd;
		gd = gcd(nn, k);
		k /= gd;
		nn /= gd;
		cout << "YES\n";
		cout << "0 0\n";
		cout << nn <<" 0\n";
		cout <<"0 " << mm << "\n";
	}
}
