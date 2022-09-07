#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int>PII;
const int N = 1e2 + 20;
PII beifenend[N];
int single1num, doublenum, single2num;
int maxrk1[N]; int maxrk2[N];
vector < vector <int> > ans(110); int anscnt; int shibaicnt;
vector < vector <int> > res(300); int rescnt;
int jilunum[N];
vector < vector <int> > houxu(200);

class Doctor
{
public:
	int num, rk1, rk2;
	int totalrk;
	int doublemarkrk;
	friend bool operator<(const Doctor& a, const Doctor& b);
}doc[N],docdb[N],docs1[N],docs2[N],backupdoc[N];

inline bool judgeequal(int a, int b)
{
	return (docdb[a].totalrk == docdb[b].totalrk);
}

bool operator<(const Doctor& a, const Doctor& b)
{
	return (a.totalrk < b.totalrk);
}

inline void printres()
{
	for (int i = 0; i < rescnt; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 0; j < res[i].size(); j++)
			{
				cout << res[i][j];
				if (j != res[i].size() - 1) cout << " ";
			}
			cout << endl;
		}
		else if (i % 2 == 0)
		{
			if (res[i].size() == 0) continue;
			int prtmp = 0;
			for (int j = 0; j < res[i].size(); j++)
			{
				if (j == 0)
				{
					prtmp = doc[res[i][j]].totalrk;
					cout << res[i][j];
				}
				else
				{
					if (doc[res[i][j]].totalrk == prtmp)
					{
						cout << " ";
						cout << res[i][j];
					}
					else
					{
						cout << endl;
						prtmp = doc[res[i][j]].totalrk;
						cout << res[i][j];
					}
				}
			}
			cout << endl;
		}
	}
}

int main()
{
	for (int i = 1; i <= 110; i++)
	{
		doc[i].num = i;
		doc[i].rk1 = 0;
		doc[i].rk2 = 0;
		doc[i].totalrk = 0;
		doc[i].doublemarkrk = 0;
	}
	string input1[110],input2[110]; int cnt1 = 1; int cnt2 = 1; int cntok = 0;int n, m; 
	cin >> n; cin.get();
	for(int oop=1;oop<=n;oop++)
	{
		getline(cin, input1[oop]);
		cnt1 += cntok; cntok = 0;
		int len = input1[oop].size();
		int a = 0;
		for (int i = 0; i < len; i++)
		{
			if (input1[oop][i] == ' ')
			{
				doc[a].rk1 = cnt1, cntok++;
				a = 0;
				continue;
			}
			a = a * 10 + (input1[oop][i] - '0');
			if (i == len - 1)
			{
				doc[a].rk1 = cnt1, cntok++;
				a = 0;
				continue;
			}
		}
	}
	cin>>m; cin.get();cntok = 0;
	for(int oop=1;oop<=m;oop++)
	{
		getline(cin, input2[oop]);
		cnt2 += cntok; cntok = 0;
		int len = input2[oop].size();
		int a = 0;
		for (int i = 0; i < input2[oop].size(); i++)
		{
			if (input2[oop][i] == ' ')
			{
				doc[a].rk2 = cnt2, cntok++;
				a = 0;
				continue;
			}
			a = a * 10 + (input2[oop][i] - '0');
			if (i == len - 1)
			{
				doc[a].rk2 = cnt2, cntok++;
				a = 0;
				continue;
			}
		}
	}
	for (int i = 1; i <= 110; i++)
	{
		doc[i].totalrk = doc[i].rk1 + doc[i].rk2;
	}
	//输入
	if (n == 0 && m == 0) 
	{
		 return 0;
	}
	if (n == 0)
	{
		for (int i = 1; i <= m; i++)
		{
			cout << input2[i] << endl;
		}
		return 0;
	}
	if (m == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << input1[i] << endl;
		}
		return 0;
	}
	//特判
	for (int i = 1; i <= 100; i++)
	{
		if (doc[i].rk1 > 0 || doc[i].rk2 > 0)
		{
			if (doc[i].rk1 > 0 && doc[i].rk2 > 0)
			{
				doublenum++;
				docdb[doublenum] = doc[i];
			}
			else if (doc[i].rk1 > 0)
			{
				single1num++;
				docs1[single1num] = doc[i];
			}
			else
			{
				single2num++;
				docs2[single2num] = doc[i];
			}
		}
	}
	//分块
	sort(docdb + 1, docdb + doublenum + 1);
	for (int i = 1; i <= doublenum; i++)
	{
		if (i == 1)
		{
			ans[anscnt].push_back(docdb[i].num);
			docdb[i].doublemarkrk = anscnt;
		}
		else
		{
			bool koka = judgeequal(i - 1, i);
			if (koka)
			{
				ans[anscnt].push_back(docdb[i].num);
				docdb[i].doublemarkrk = anscnt;
			}
			else if (!koka)
			{
				anscnt++;
				ans[anscnt].push_back(docdb[i].num);
				docdb[i].doublemarkrk = anscnt;
			}
		}
	}
	//将有两个排名的医生压入答案;
	int single1judgecnt = 0;bool singleoncejudge = true;int targetrkintotal = 0;
	for (int i = 1; i <= single1num; i++)
	{
		single1judgecnt = 0;
		singleoncejudge = true;
		targetrkintotal = 0;
		for (int j = 1; j <= doublenum; j++)
		{
			if (docdb[j].rk1 == docs1[i].rk1)
			{
				single1judgecnt++;
				if (single1judgecnt >= 2)
				{
					if (docdb[j].totalrk != docdb[targetrkintotal].totalrk)
					{
						singleoncejudge = false;
						break;
					}
				}
				targetrkintotal = j;
			}
		}
		if (single1judgecnt == 0)
		{
			singleoncejudge = false;
		}
		if (singleoncejudge)
		{
			int biaoji = docdb[targetrkintotal].doublemarkrk;
			ans[biaoji].push_back(docs1[i].num);
		}
		else if (!singleoncejudge && single1judgecnt == 0)
		{
			shibaicnt++;
			backupdoc[shibaicnt] = docs1[i];
		}
	}
	//将只有single1中一个排名符合条件2.1的压入答案，不能确定的滚进Back
	for (int i = 1; i <= single2num; i++)
	{
		single1judgecnt = 0;
		singleoncejudge = true;
		targetrkintotal = 0;
		for (int j = 1; j <= doublenum; j++)
		{
			if (docdb[j].rk2 == docs2[i].rk2)
			{
				single1judgecnt++;
				if (single1judgecnt >= 2)
				{
					if (docdb[j].totalrk != docdb[targetrkintotal].totalrk)
					{
						singleoncejudge = false;
						break;
					}
				}
				targetrkintotal = j;
			}
		}
		if (single1judgecnt == 0)
		{
			singleoncejudge = false;
		}
		if (singleoncejudge)
		{
			int biaoji = docdb[targetrkintotal].doublemarkrk;
			ans[biaoji].push_back(docs2[i].num);
		}
		else if (!singleoncejudge && single1judgecnt == 0)
		{
			shibaicnt++;
			backupdoc[shibaicnt] = docs2[i];
		}
	}
	//将只有single2中一个排名符合条件2.1的压入答案，不能确定的滚进Back
	for (int i = 1; i <= shibaicnt; i++)
	{
		bool nengfoupipei = true;
		int pipeichenggong = 0;
		if (backupdoc[i].rk1 > 0)//参加了第一场比赛
		{
			for (int j = 1; j <= doublenum; j++)
			{
				if (docdb[j].rk1 > backupdoc[i].rk1)
				{
					for (int k = 1; k <= doublenum; k++)
					{
						if (k < j && docdb[k].doublemarkrk != docdb[j].doublemarkrk) continue;
						if (k == j) continue;
						if (docdb[k].rk1 < backupdoc[i].rk1)
						{
							nengfoupipei = false;
							break;
						}
					}
					if (!nengfoupipei) break;
					pipeichenggong = j;
					break;
				}
				if (j == doublenum && docdb[j].rk1 < backupdoc[i].totalrk)
				{
					int biaoji = anscnt + 1;
					houxu[biaoji].push_back(backupdoc[i].num);
					nengfoupipei = false;
				}
			}
			if (!nengfoupipei) continue;
			int biaoji = docdb[pipeichenggong].doublemarkrk;
			houxu[biaoji].push_back(backupdoc[i].num);
		}
		else if (backupdoc[i].rk2 > 0)//参加了第2场比赛
		{
			for (int j = 1; j <= doublenum; j++)
			{
				if (docdb[j].rk2 > backupdoc[i].rk2)
				{
					for (int k = 1; k <= doublenum; k++)
					{
						if (k < j && docdb[k].doublemarkrk != docdb[j].doublemarkrk) continue;
						if (k == j) continue;
						if (docdb[k].rk2 < backupdoc[i].rk2)
						{
							nengfoupipei = false;
							break;
						}
					}
					if (!nengfoupipei) break;
					pipeichenggong = j;
					break;
				}
				if (j == doublenum && docdb[j].rk2 < backupdoc[i].rk2)
				{
					int biaoji = anscnt + 1;
					houxu[biaoji].push_back(backupdoc[i].num);
					nengfoupipei = false;
				}
			}
			if (!nengfoupipei) continue;
			int biaoji = docdb[pipeichenggong].doublemarkrk;
			houxu[biaoji].push_back(backupdoc[i].num);
		}
	}
	//处理不能确定的
	for (int i = 0; i <= anscnt + 1; i++)
	{
		for (int j = 0; j < houxu[i].size(); j++)
		{
			beifenend[j].second = houxu[i][j];
			beifenend[j].first = doc[houxu[i][j]].totalrk;
		}
		sort(beifenend, beifenend + houxu[i].size());
		for (int j = 0; j < houxu[i].size(); j++)
		{
			houxu[i][j] = beifenend[j].second;
		}
	}
	//排序;
	for (int i = 0; i <= anscnt; i++)
	{
		res[rescnt] = (houxu[i]), rescnt++;
		res[rescnt] = (ans[i]), rescnt++;
	}
	res[rescnt] = (houxu[anscnt + 1]), rescnt++;
	printres();
	//压入res,并打印 ;
	return 0;
}