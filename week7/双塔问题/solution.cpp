#define re register
#include "bits/stdc++.h"

using namespace std;
const int N = 110;
int n1, n2;
int a[N], b[N];
int dp[N][N];
int tacnt = 0;

int main()
{
	cin >> n1 >> n2;
	cin.get();
	while (n1 != 0)
	{
		string temp;
		getline(cin, temp);
		for (re int i = 0; i < n1; i++)
		{
			a[i + 1] = temp[i << 1];
		}
		getline(cin, temp);
		for (re int i = 0; i < n2; i++)
		{
			b[i + 1] = temp[i << 1];
		}
		for (re int i = 1; i <= n1; i++)
		{
			for (re int j = 1; j <= n2; j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
		tacnt++;
		cout << "Twin Towers #" << tacnt << endl;
		cout << "Number of Tiles : " << dp[n1][n2] << endl;
		cin >> n1 >> n2;
		cin.get();
	}
	return 0;
}