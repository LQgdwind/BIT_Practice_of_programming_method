#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream";
#include "deque";
#include "vector";
#include "cstring";

using namespace std;

const int N = 2e6 + 10;

int ne[N], e[N], h[N], idx;

int d[N];

int citydistance[N];

int cnt = 0;

deque<int> q;

int node;

void addedge(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	d[b]++;
	h[a] = idx++;
}

void topSort()
{
	loop(i, 1, node)
	{
		if (d[i] == 0)
		{
			q.push_back(i);
			citydistance[i] = 1;
		}
	}
	while (q.size())
	{
		int x = q.front();
		q.pop_front();
		for (int i = h[x]; i != -1; i = ne[i])
		{
			int y = e[i];
			citydistance[y] = max(citydistance[y], citydistance[x] + 1);
			if (d[y] == 0) continue; 
			if (--d[y] == 0) //每次读到这个点，入度减一。入度为零时就可以扔进队列了
			{
				q.push_back(y);
			}
		}
	}
}

int  m;

int main()
{
	memset(h, -1, sizeof(h));
	cin >> node >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
	}
    topSort();
	loop(i, 1, node)
	{
		cout << citydistance[i] << endl;
	}
	return 0;
}