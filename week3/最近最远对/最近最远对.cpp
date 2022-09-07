#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "vector"
#include "cmath"
#include "cstdio"

using namespace std;
typedef pair<double, double> PDD;
int n;
vector<PDD> point;

double maxd = -100000.1;
double mind = 100000.1;

double distance(PDD a,PDD b)
{
	double temp1 = a.first - b.first;
	double temp2 = a.second - b.second;
	double ans = sqrt(temp1 * temp1 + temp2 * temp2);
	return ans;
}
int main()
{
	int n;
	cin >> n;
	point.emplace_back(PDD(0.0,0.0));
	loop(i,1,n)
	{
		PDD temp;
		cin >> temp.first;
		cin >> temp.second;
		point.emplace_back(temp);
	}
	loop(i, 1, n)
	{
		loop(j, i, n)
		{
			if (i == j) continue;
			double restemp = distance(point[i], point[j]);
			if (restemp > maxd) maxd = restemp;
			if (restemp < mind) mind = restemp;
		}
	}
	printf("%.2f %.2f\n", mind, maxd);
	return 0;
}