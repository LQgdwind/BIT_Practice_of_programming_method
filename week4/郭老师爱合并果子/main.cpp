#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define N 1000010

#include "stdio.h"
#include "stdlib.h"

typedef long long ll;
int n;
ll res = 0;
ll h[N], ph[N], hp[N];
int size;
int idx = 0;

void myswap(ll* a, ll* b)
{
	ll temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void heap_swap(int a, int b)
{
	myswap(&ph[hp[a]], &ph[hp[b]]);
	myswap(&hp[a], &hp[b]);
	myswap(&h[a], &h[b]);
}

void down(int u)
{
	int t = u;
	if (u * 2 <= size)
	{
		if(h[u * 2] < h[t])
		t = u * 2;
	}//先比左孩子
	if (u * 2 + 1 <= size)
	{
		if(h[u * 2 + 1] < h[t])
		t = u * 2 + 1;
	}//再比右孩子
	if (u != t)
	{
		heap_swap(u, t);
		down(t);
	}//不一样就换，然后递归
}

void up(int u)
{
	while (u >> 1 && h[u] < h[u >> 1])
	{
		heap_swap(u, u >> 1);
		u >>= 1;
	}
}

void insert(ll a)
{
	size++;
	idx++;
	ph[idx] = size, hp[size] = idx;
	h[size] = a;
	up(size);
}

void erase()
{
	heap_swap(1, size);
	size--;
	down(1);
}

int main()
{
	bool readOK, writeOK;
	readOK=freopen("1.in", "r", stdin);
	writeOK=freopen("1.out", "a+", stdout);
	scanf("%d", &n);
	ll temp = 0;
	loop(i, 1, n)
	{
		scanf("%lld", &temp);
		insert(temp);
	}
	while (size > 1)
	{
		ll temp1 = h[1];
		erase();
		ll temp2 = h[1];
		erase();
		ll temp3 = temp1 + temp2;
		insert(temp3);
		res += temp3;
	}
	printf("%lld\n", res);
	if (readOK) fclose(stdin);
	if(writeOK) fclose(stdout);
}