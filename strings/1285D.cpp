#include <iostream>
#include <algorithm>

using namespace std;

const int powik = 29;
const int maxik = 22;

int trie[1 << maxik][2];
int cnt = 0,ans=0,n,num;
const int root = 0;
int solve(int pow, int indx);
void makeTrieGreatAgain(int num);
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		makeTrieGreatAgain(num);
	}
	ans =solve(powik, root);
	cout << ans;
	return 0;
}
int solve(int pow, int indx)
{
	if (pow == -1)
	{
		return 0;
	}
	if (trie[indx][0] == 0)
	{
		return solve(--pow, trie[indx][1]);
	}
	else if (trie[indx][1] == 0)
	{
		return solve(--pow, trie[indx][0]);
	}
	return (1<<pow)+min(solve(pow-1, trie[indx][0]), solve(pow-1, trie[indx][1]));
}
void makeTrieGreatAgain(int num)
{
	int troot = root;
	for (int i = powik; i >= 0; i--)
	{
		int push = 1 << i;
		bool p = push & num;
		if (!(trie[troot][p]))
		{
			trie[troot][p] = ++cnt;
		}
		troot = trie[troot][p];
	}
	return;
}
