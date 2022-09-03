#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

const string a = "Ashish", u = "Utkarsh";
int main()
{
	int t;
	ll k, d;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> d >> k;
		d *= d;
		ll halfD = d / 2;
		halfD = sqrt(halfD);
		ll litteR = halfD / k;
		ll es = k * litteR;
		if (es*es + (es + k)*(es + k) <= d)
		{
			cout << a << "\n";
		}
		else
		{
			cout << u << "\n";
		}
	}
	//system("pause");
}
