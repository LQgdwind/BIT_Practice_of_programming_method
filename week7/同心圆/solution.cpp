#include "bits/stdc++.h"
using namespace std;
const long double Pi = 3.1415926535897932384626433832795;long double n, m;long double ans = 0;

int main()
{
	cin >> n >> m;
	long double t = (int)(2 * m / Pi);long double tmp1 = n * m * (1 + n);long double tmp2 = 0;
	for (int i = 1; i <= n; i++)
	{
		double it = i;long double tmp3 = 2 * m * (n * n + it * it + n);long double tmp4 = 2 * n * m * (m - 1) * (2 * it + n + 1);long double tmp5 = 4 * m * t * (2 * it * n + it - it * it);long double tmp6 = t * (t + 1) * it * (2 * n - it + 1) * Pi;
		tmp2 += tmp3 + tmp4 - tmp5 + tmp6;
	}
	ans = tmp2 + tmp1, ans /= 2.0;
	if (m > 1)  printf("%.10Lf", ans);
	else if (m == 1) ans -= tmp1, printf("%.10Lf", ans);
	return 0;
}