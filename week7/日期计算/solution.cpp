#include "bits/stdc++.h"

using namespace std;

int t;
int m1, d1, m2, d2, x;

int pina[20] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int runa[20] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
bool pin()
{
	if (m1 == 2 && d1 == 29 || m2 == 2 && d2 == 29) return false;
	int yue = m1, ri = d1, pe = x;
	int through = pina[yue] - ri;
	pe -= through;
	if (pe <= 0)
	{
		pe += through;
		ri += pe;
		if (m2 == yue && d2 == ri) return true;
		else return false;
	}
	while (pe > 0)
	{
		yue++;
		yue %= 12;
		if (yue == 0) yue = 12;
		pe -= pina[yue];
	}
	pe += pina[yue];
	ri = pe;
	if (m2 == yue && d2 == ri) return true;
	else return false;
}

bool run()
{
	int yue = m1, ri = d1, pe = x;
	int through = runa[yue] - ri;
	pe -= through;
	if (pe <= 0)
	{
		pe += through;
		ri += pe;
		if (m2 == yue && d2 == ri) return true;
		else return false;
	}
	while (pe > 0)
	{
		yue++;
		yue %= 12;
		if (yue == 0) yue = 12;
		pe -= runa[yue];
	}
	pe += runa[yue];
	ri = pe;
	if (m2 == yue && d2 == ri) return true;
	else return false;
}

int main()
{
	cin >> t;
	while (t--)
	{
		scanf("%d%d%d%d%d", &m1, &d1, &m2, &d2, &x);
		bool judge1 = pin();
		bool judge2 = run();
		if (m1 > m2 || (m1 == m2 && d1 > d2))
		{
			if (m1 == 2 && d1 == 29)
			{
				cout << "R" << endl;
				continue;
			}
			else if (m2 == 2 && d2 == 29)
			{
				cout << "P" << endl;
				continue;
			}
			else if (m1 <= 2)
			{
				if (judge1 && judge2) cout << "?" << endl;
				else if (judge1 && !judge2) cout << "P" << endl;
				else if (judge2 && !judge1) cout << "R" << endl;
				continue;
			}
			else if (m1 >= 3&& m2 >=3)
			{
				if (judge2) cout << "P" << endl;
				else cout << "?" << endl;
				continue;
			}
			else if (m1 >= 3 && m2 <= 2)
			{
				if (judge1 && judge2) cout << "?" << endl;
				else if (judge1 && !judge2) cout << "P" << endl;
				else if (judge2 && !judge1) cout << "R" << endl;
				continue;
			}
		}
		if (judge1 && judge2) cout << "?" << endl;
		else if (judge1 && !judge2) cout << "P" << endl;
		else if (judge2 && !judge1) cout << "R" << endl;
	}
	return 0;
}
