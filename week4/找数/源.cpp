#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "vector"

using namespace std;

typedef long long ll;

vector<ll> numbers;

int n;
int cnt = 0;
int main()
{
	cin >> n;
	ll input = 0;
	loop(i, 1, n)
	{
		cin >> input;
		numbers.push_back(input);
	}
	int left = 0;
	int right = 0;
	cin >> left >> right;
	if (left > right)
	{
		cout << "No Result!" << endl;
		return 0;
	}
	vector<ll>::iterator ib = lower_bound(numbers.begin(), numbers.end(), left);
	vector<ll>::iterator jb = lower_bound(numbers.begin(), numbers.end(), right);
	if (jb != numbers.end()) 
	while (*jb == right)
	{
		jb++;
		if (jb == numbers.end()) break;
	}
	for (vector<ll>::iterator i = ib; i != jb; i++)
	{
		cout << *i << endl;
		cnt++;
	}
	if (cnt == 0) cout << "No Result!" << endl;
	return 0;
}