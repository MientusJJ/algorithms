#include <iostream>

using namespace std;

int main()
{
	bool o = false;
	int n, m, k,x,y;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		if (x <= 5 || y <= 5 || (n - x) <= 4 || (m - y) <= 4)
		{
			o = true;
		}
	}
	if (o)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;

}
