#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "vector"

using namespace std;
const int maxn = 1005;
int n;
bool good[maxn][maxn];
void guessdalao(int n); // you should finish this
int better(int a, int b)
{
	if (a <= 0 || a > n || b <= 0 || b > n) return -1;
	return good[a][b];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int t;
			scanf("%d", &t);
			good[i][j] = t;
		}
	guessdalao(n);
	return 0;
}

vector<int> dalao;
vector<int> backup;

void guessdalao(int n)
{
	for (int i = 1; i <= n; i++) dalao.emplace_back(i);
	while (dalao.size() > 1)
	{
		if (dalao.size() & 1)
		{
			for (int i = 0, j = dalao.size() - 1; i < (dalao.size() - 1) / 2; i++, j--)
			{
				int tempjudge = better(dalao[i], dalao[j]);
				if (tempjudge == 1) backup.emplace_back(dalao[i]);
				else if (tempjudge == 0) backup.emplace_back(dalao[j]);
			}
			backup.emplace_back(dalao[(dalao.size() - 1) / 2]);
			dalao.clear();
			dalao.assign(backup.begin(), backup.end());
			backup.clear();
		}
		else
		{
			for (int i = 0, j = dalao.size() - 1; i <= dalao.size() / 2-1; i++, j--)
			{
				int tempjudge = better(dalao[i], dalao[j]);
				if (tempjudge == 1) backup.emplace_back(dalao[i]);
				else if (tempjudge == 0) backup.emplace_back(dalao[j]);
			}
			dalao.clear();
			dalao.assign(backup.begin(), backup.end());
			backup.clear();
		}
	}
	int realdalao = dalao[0];
	bool st = true;
	for (int i = 1; i <= n; i++)
	{
		if (realdalao == i) continue;
		int judge1 = better(realdalao, i);
		int judge2 = better(i, realdalao);
		if (judge1 != 1 || judge2 != 0)
		{
			st = false;
			break;
		}
	}
	if (st) cout << realdalao << endl;
	else cout << -1 << endl;
}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */