#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

const int N = 1010;

string target[N];
string print[N];

string BF;

int n;
int cnt = -1;

int main()
{
	cin >> n;
	loop(i, 1, n)
	{
		cin >> target[i];
	}
	cin >> BF;
	int length = BF.size();
	loop(i, 1, n)
	{
		int j = 0;
		int k = 0;
		while (k<=length)
		{
			if (target[i][j] == BF[k])
			{
				j++; k++;
				if (k == length)
				{
					print[++cnt] += target[i];
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	if (cnt == -1)
	{
		cout << "No Result!" << endl;
		return 0;
	}
	sort(print, print + cnt + 1);
	loop(i, 0, cnt)
	{
		cout << print[i] << endl;
	}
}