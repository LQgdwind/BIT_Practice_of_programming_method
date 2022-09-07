#include "bits/stdc++.h"
using namespace std;
int t; stringstream ss; string input; int a[4];
int main()
{
	cin >> t, cin.get();
	while (t--)
	{
		ss.clear(); getline(cin, input); ss << input; for (int i = 0; i <= 3; i++) ss >> a[i];
		int b = (a[0] - a[2]) ^ (a[1] - a[3]) ^ (a[2] - 1) ^ (a[3] - 1);
		if (b) cout << "Alice" << endl;
		else  cout << "Bob" << endl;
	}
	return 0;
}