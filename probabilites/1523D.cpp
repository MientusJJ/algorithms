#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <fstream>
#include <chrono>
#include <random>
#define es ios::sync_with_stdio(false);cin.tie(nullptr);
//#define TXTcreate freopen("C:/Temp/output.txt","w",stdout);freopen("input.txt","w",stdout);
#define TXT  freopen("C:/Temp/input.txt","r",stdin); freopen("C:/Temp/output.txt","w",stdout);
//#define x first
//#define y second
#define all(v) (v).begin(),(v).end()
#define prec(i) cout << std::fixed << std::setprecision(i)
#define randomizer mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
const int maxik = 2e5 + 7;
const int maxN = 1 << 20;
const int INF = 0x3f3f3f3f;
const int modik = 1e9 + 7;
const int tight = 2;
const int hash2 = 11777;
const int hash1 = 12269;
const double eps = 1e-6;
const int modik2 = 998'244'353;

int n, m, p, half, res=0;
string traders[maxik];
vector<int> curr;
bitset<30> word;
string show;
int main()
{
	es;
	randomizer;
	//TXT;
	cin >> n >> m >> p;
	show=string(m, '0');
	half = (n + 1) / 2;
	for (int i = 1; i <= n; i++)
	{
		cin >> traders[i];
	}
	int randik = 30;
	while (randik--)
	{
		int indx = rng() % n + 1;
		curr.clear();
		for (int i = 0; i < traders[indx].size(); i++)
		{
			if (traders[indx][i] == '1')
			{
				curr.push_back(i);
			}
		}
		int sizes = curr.size();
		vector<int> mask(1 << (sizes+1), 0);
		for (int i = 1; i <= n; i++)
		{
			int hm = 0;
			for (int j = 0; j < sizes; j++)
			{
				if (traders[i][curr[j]] == '1')
				{
					hm |= 1 << j;
				}
			}
			mask[hm]++;
		}
		for (int i = 0; i < sizes; i++)
		{
			for (int j = 0; j < (1<<sizes); j++)
			{
				if (!((1 << i) & j))
				{
					mask[j] += mask[j | (1 << i)];
				}
			}
		}
		for (int i = 0; i < (1 << sizes); i++)
		{
			word.set();
			word &= i;
			int bit = word.count();
			if (bit > res && mask[i] >= half)
			{
				res = bit;
				string temp(m, '0');
				for (int j = 0; j < sizes; j++)
				{
					if (1 << j & i)
					{
						temp[curr[j]] = '1';
					}
				}
				show = temp;
			}
		}
	}
	cout << show << endl;
	return 0;
}
