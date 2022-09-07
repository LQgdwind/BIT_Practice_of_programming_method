#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "iostream"
#include "cstdio"
#include "string"
#include "cstring"
#include "algorithm"
#include "vector"

using namespace std;
const int maxn = 200005;
int n;
int a[maxn];
void findminandmax(int n); // you should finish this
int cmp(int i, int j)
{
	if (i <= 0 || i > 2 * n || j <= 0 || j > 2 * n) return -2;
	if (a[i] > a[j]) return 1;
	if (a[i] == a[j]) return 0;
	if (a[i] < a[j]) return -1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		scanf("%d", &a[i]);
	findminandmax(n);
	return 0;
}

vector<int> tempmin;
vector<int> tempmax;
void findminandmax(int n)
{
	int number = 2 * n;
	for (int i = 1, j = number; i <= n; i++, j--)
	{
		int result = cmp(i, j);
		if (result == 1)
		{
			tempmax.emplace_back(i);
			tempmin.emplace_back(j);
		}
		else if (result == 0 || result == -1)
		{
			tempmax.emplace_back(j);
			tempmin.emplace_back(i);
		}
		else if (result == -2) exit(0);
	}
	int resmax = tempmax.front();
	int resmin = tempmin.front();
	if (n > 1)
	for (vector<int>::iterator i = tempmax.begin()+1; i != tempmax.end(); i++)
	{
		int result = cmp(*i, resmax);
		if (result == 1) resmax = *i;
	}
	if (n > 1)
	for (vector<int>::iterator i = tempmin.begin()+1; i != tempmin.end(); i++)
	{
		int result = cmp(*i, resmin);
		if (result == -1) resmin = *i;
	}
	cout << resmin <<" "<< resmax << endl;
}


