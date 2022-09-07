//#pragma GCC optimize(3,"Ofast","inline")

#define _CRT_SECURE_NO_WARNINGS  
#define loop(i,a,b) for(int i=a;i<=b;i++)  
#include "cstdio"
#include "iostream"
#include "string"
#include "unordered_map"
using namespace std;
typedef pair<int, string> PIS;
unordered_map <int, string> map1;
int n;
void yuchuli()
{
	map1.insert({ 0,"2(0)" }); map1.insert({ 1,"2" }); map1.insert({ 2,"2(2)" }); map1.insert({ 3,"2(2+2(0))" }); map1.insert({ 4,"2(2(2))" }); map1.insert({ 5,"2(2(2)+2(0))" }); map1.insert({ 6,"2(2(2)+2)" }); map1.insert({ 7,"2(2(2)+2+2(0))" }); map1.insert({ 8,"2(2(2+2(0)))" }); map1.insert({ 9,"2(2(2+2(0))+2(0))" }); map1.insert({ 10,"2(2(2+2(0))+2)" }); map1.insert({ 11,"2(2(2+2(0))+2+2(0))" }); map1.insert({ 12,"2(2(2+2(0))+2(2))" }); map1.insert({ 13,"2(2(2+2(0))+2(2)+2(0))" }); map1.insert({ 14,"2(2(2+2(0))+2(2)+2)" }); map1.insert({ 15,"2(2(2+2(0))+2(2)+2+2(0))" }); map1.insert({ 16,"2(2(2(2)))" }); map1.insert({ 17,"2(2(2(2))+2(0))" }); map1.insert({ 18,"2(2(2(2))+2)" }); map1.insert({ 19,"2(2(2(2))+2+2(0))" }); map1.insert({ 20,"2(2(2(2))+2(2))" }); map1.insert({ 21,"2(2(2(2))+2(2)+2(0))" }); map1.insert({ 22,"2(2(2(2))+2(2)+2)" }); map1.insert({ 23,"2(2(2(2))+2(2)+2+2(0))" }); map1.insert({ 24,"2(2(2(2))+2(2+2(0)))" }); map1.insert({ 25,"2(2(2(2))+2(2+2(0))+2(0))" }); map1.insert({ 26,"2(2(2(2))+2(2+2(0))+2)" }); map1.insert({ 27,"2(2(2(2))+2(2+2(0))+2+2(0))" }); map1.insert({ 28,"2(2(2(2))+2(2+2(0))+2(2))" }); map1.insert({ 29,"2(2(2(2))+2(2+2(0))+2(2)+2(0))" }); map1.insert({ 30,"2(2(2(2))+2(2+2(0))+2(2)+2)" });
}

int main()
{
	cin >> n; int m = n; string erjinzhi, ans;
	yuchuli();
	while (m)
	{
		if (m & 1) erjinzhi.insert(0,"1");else erjinzhi.insert(0, "0");m = m >> 1;
	}
	loop(i,0,erjinzhi.size()-1)
		if (erjinzhi[i] == '1')
			ans = ans + map1[erjinzhi.size()-i-1] + '+';
	ans.pop_back();
	cout << ans << endl;
	return 0;
}