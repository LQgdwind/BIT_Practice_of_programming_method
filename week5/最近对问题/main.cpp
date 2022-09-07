#pragma GCC optimize(3,"Ofast","inline")

#define _CRT_SECURE_NO_WARNINGS  
#define loop(i,a,b) for(long long i=a;i<=b;i++)  

#include "iostream"
#include "algorithm"
#include "vector"
#include "cmath"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const int N = 1e6 + 10;
PII p[N], q[N];
//typedef vector<PII>::iterator Iter;

ll n;

bool cmp1(PII x, PII y)
{
	return x.first < y.first;
}
bool cmp2(PII x, PII y)
{
	return x.second < y.second;
}

double getdistance(PII x, PII y)
{
	double temp = sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
	return temp;
}

void calculate(int l, int r, double& d)
{
	if (r - l <= 1)
	{
		return;
	}
	int mid = l + (r - l) / 2;
	double midx = p[mid].first;
	calculate(l, mid, d);
	calculate(mid, r, d);
	inplace_merge(p+l, p+mid, p+r, cmp2);
	int num = 0;
	for (int i = l; i != r; i++)
	{
		if (midx >= p[i].first - d && midx <= d + p[i].first)
		{
			q[num++]= p[i];
		}
	}
	for (int i = 0, j = 0; i != num; i++)
	{
		while (j != num && q[j].second <= q[i].second + d)
			j++;
		for (int k = i + 1; k != j; k++)
			d = min(d, getdistance(q[i], q[k]));
	}
}

int quickread() 
{
	int w = 1, c, ret;
	while ((c = getchar()) > '9' || c < '0') w = (c == '-' ? -1 : 1); ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + c - '0';
	return ret * w;
}

int main()
{
	bool read = freopen("1.in", "r+", stdin);
	bool write = freopen("1.out", "a+", stdout);
	n = quickread();
	loop(i, 0, n-1)
	{
		p[i].first = quickread();
		p[i].second= quickread();
	}
	sort(p, p+n, cmp1);
	double d = 1e18;
	calculate(0, n, d);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(0);
	cout << d*d << endl;
	return 0;
}