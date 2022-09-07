#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

typedef long long ll;
typedef pair<ll, ll>PII;

vector<PII> v;
ll ans;

bool cmp1(PII x, PII y)
{
	return (x.first < y.first);
}
bool cmp2(PII x, PII y)
{
	return (x.second < y.second);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		PII temp;
		cin >> temp.first;
		cin >> temp.second;
		v.push_back(temp);
	}
	int mid = n >> 1;
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < n; i++)
	{
		ans = ans + abs(v[i].first - v[mid].first);
	}
	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < n; i++)
	{
		ans = ans + abs(v[i].second - v[mid].second);
	}
	cout << ans << endl;
	return 0;
}