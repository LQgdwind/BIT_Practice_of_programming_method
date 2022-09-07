#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(long long i=a;i<=b;i++)

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "sstream"
#include "cstring"
#include "cmath"

using namespace std;

typedef long long ll;

ll l, r;

ll result[100];



int cnt = -1;
void shuixianhua(ll x,ll y)
{
	stringstream ss;
	string temp;
	ll a[12];
	ll restemp = 0;
	loop(i, x, y)
	{
		memset(a, 0, sizeof(a));
		restemp = 0;
		ss.clear();
		temp.clear();
		ss << i;
		ss >> temp;
		loop(j, 0, (ll)(temp.size()-1))
		{
			int hello = temp[j] - '0';
			a[j] =(ll)hello;
			restemp = restemp + (ll)pow(a[j],temp.size());
		}
		if (restemp == i) result[++cnt] = restemp;
	}
}

vector<ll> dabiao()
{
	vector<ll> special = { 153,370,371,407,1634,8208,9474,93084, 92727, 54748,548834,9800817,4210818,1741725,9926315,24678050,24678051,88593477,146511208,472335975,534494836,912985153 };
	return special;
}

int main()
{
	cin >> l >> r;
	if(r<100000)
	{
		shuixianhua(l, r);
		cout << cnt + 1 << endl;
		loop(i, 0, cnt) cout << result[i] << endl;
	}
	else
	{
		vector<ll> nb = dabiao();
		sort(nb.begin(), nb.end());
		int nbcnt = 0;
		for (vector<ll>::iterator i = nb.begin(); i != nb.end(); i++)
		{
			if (l <= *i && r >= *i)nbcnt++;
		}
		cout << nbcnt << endl;
		for (vector<ll>::iterator i = nb.begin(); i != nb.end(); i++)
		{
			if (l <= *i && r >= *i) cout << *i << endl;
		}
	}
	return 0;
}