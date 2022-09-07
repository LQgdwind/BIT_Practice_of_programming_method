#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

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
	int* m = new int;
	*m= tempword.size();
	maxw = max(maxw,*m);
	st[x] = st[x] + 1;
	loop(i, 1, n)
	{
		if (graph[x][i])
			if (st[i] < 2)
			{
				string hello = tempword;
				loop(oop, 0, word[i].substr(graph[x][i]).size()-1)
				{
					hello.append(word[i].substr(oop, 1));
				}
				worddfs(hello, i);
			}
	}
	st[x] = st[x] - 1;
}

void judgelength(int x,int y)
{
	loop(k, 1, min(word[x].size() - 1, word[y].size() - 1))
	{
		if (word[x].substr(word[x].size() - k, k) == word[y].substr(0, k))
		{
			graph[x][y] = k;
			break;
		}
	}
}

void yuchuli()
{
	loop(i, 1, n)
	{
		loop(j, 1, n)
		{
			judgelength(i, j);
		}
	}
}

void dfsjudge(int op)
{
	if (word[0].c_str()[0] == word[op].c_str()[0])
		worddfs(word[op], op);
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
		dfsjudge(i);
	}
	cout << maxw << endl;
	return 0;
}