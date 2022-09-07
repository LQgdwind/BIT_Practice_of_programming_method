/*#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string word[10010];
int g[1010][1010];
int use[1010];
char head;
int n;
int ans = 0;
void dfs(string dragon, int last)
{
	ans = max(ans, (int)dragon.size());
	use[last]++;
	for (int i = 1; i <= n; i++)
	{
		if (g[last][i] && use[i] < 2)
			dfs(dragon + word[i].substr(g[last][i]), i);  //第几个字符之后的字符串 
	}
	use[last]--;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> word[i];
	cin >> head;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			string a = word[i], b = word[j];
			for (int k = 1; k < min(a.size(), b.size()); k++)
				if (a.substr(a.size() - k, k) == b.substr(0, k))
				{
					g[i][j] = k;
					break;
				}
		}

	for (int i = 1; i <= n; i++)
		if (word[i][0] == head)
			dfs(word[i], i);

	cout << ans << endl;
	return 0;
}
/*#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "string"
#include "algorithm"
#include "cstring"

using namespace std;

int n;

string word[100];
int st[100];
int graph[100][100];
int maxw = 0;

void worddfs(string tempword, int x)
{
	maxw = (maxw,(int) tempword.size());
	st[x] = st[x] + 1;
	loop(i, 1, n)
	{
		if (st[x] == 2)continue;
		if (graph[x][i] == 0) continue;
		worddfs(tempword + word[i].substr(graph[x][i]), i);
	}
	st[x] = st[x] - 1;
}

void yuchuli()
{
	loop(i, 1, n)
	{
		loop(j, 1, n)
		{
			loop(k, 1, min(word[i].size() - 1, word[j].size() - 1))
			{
				if (word[i].substr(word[i].size() - k, k) == word[j].substr(0, k))
				{
					graph[i][j] = k;
					break;
				}
			}
		}
	}
}

int main()
{
	memset(st, 0, sizeof(st));
	cin >> n;
	loop(i, 1, n)
	{
		cin >> word[i];
	}
	cin >> word[0];
	yuchuli();
	loop(i, 1, n)
	{
		if (word[0].c_str()[0] == word[i].c_str()[0])
			worddfs(word[i], i);
	}
	cout << maxw << endl;
	return 0;
}*/