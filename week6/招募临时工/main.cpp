#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "queue"
#include "cstring"

using namespace std;

const int N = 1e3 + 10;
const int M = 2e4 + 10;

class Edge
{
public:int e, ne, cost, capacity;
}edge[M<<1];
int h[N]; int idx = 1;

class employee
{
public:
	int left, right, cost;
	employee();
};

queue<int> q;
int n, m;
int yuan, hui;
int task[N];
bool st[N];
int d[N], pre[N];
int ans;

employee::employee()
{
	this->cost = 0; this->left = 0; this->right = 0;
}

void add(int a, int b, int z, int c)
{
	edge[++idx].e = b;
	edge[idx].ne = h[a];
	edge[idx].capacity = z;
	edge[idx].cost = c;
	h[a] = idx;//Õý±ß;
	edge[++idx].e = a;
	edge[idx].ne = h[b];
	edge[idx].capacity = 0;
	edge[idx].cost = -c;
	h[b] = idx;//¸º±ß;
}

inline int spfa() 
{
	memset(d, 0x3f, sizeof(d));
	memset(pre, 0, sizeof(pre));
	q.push(yuan); 
	d[yuan] = 0, st[yuan] = true;
	while (!q.empty()) 
	{
		int x = q.front(); q.pop(); st[x] = false;
		for (int i = h[x]; i!=-1; i = edge[i].ne) 
		{
			int y = edge[i].e;
			int c = edge[i].cost;
			if (edge[i].capacity && d[x] + c < d[y]) 
			{
				d[y] = d[x] + c;
				pre[y] = i;
				if (!st[y])
				{
					st[y] = true;
					q.push(y);
				}
			}
		}
	}
	return pre[hui] != 0;
}

int main()
{
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	yuan = 0; hui = n + 2;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", task + i);
	}
	for (int i = 1; i <= n + 1; i++)
	{
		if (task[i] - task[i - 1] > 0)
		{
			add(yuan, i, task[i] - task[i - 1], 0);
		}
		else
		{
			add(i, hui, task[i - 1] - task[i], 0);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		add(i + 1, i, 0x3f3f3f3f, 0);
	}
	employee sb;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &sb.left, &sb.right, &sb.cost);
		add(sb.left, sb.right+1, 0x3f3f3f3f, sb.cost);
	}
	while (spfa())
	{
		int f = 0x3f3f3f3f;
		for (int i = pre[hui]; i; i = pre[edge[i ^ 1].e])
		{
			f = min(f, edge[i].capacity);
		}
		for (int i = pre[hui]; i; i = pre[edge[i ^ 1].e])
		{
			edge[i].capacity -= f;
			edge[i ^ 1].capacity += f;
		}
		ans += d[hui] * f;
	}
	cout << ans << endl;
	return 0;
}