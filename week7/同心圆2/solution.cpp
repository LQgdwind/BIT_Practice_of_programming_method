#include "bits/stdc++.h"
using namespace std;
typedef long double ld;
const int N = 1e5 + 10; const long double Pi = 3.1415926535897932384626433832795;
ld n, a[N], c[N], res;
int main()
{
	cin >> n; for (int i = 1; i <= n; i++) cin >> a[i], a[i] = a[i] * 2 * Pi / 360.0;
	sort(a + 1, a + (int)n + 1);
	for (int i = 1; i <= n; i++) c[i] = a[i] - 2.0 * Pi * (double)i / n;
	sort(c + 1, c + (int)n + 1);
	int mid = (1 + (int)n) >> 1;
	for (int i = 1; i <= n; i++) res += fabs(c[i] - c[mid]);
	printf("%.25Lf", res);
	return 0;
}