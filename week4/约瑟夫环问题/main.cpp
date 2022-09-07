#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"; 
#include "vector"; 
#include "cstdio"; 

using namespace std;

int n, m;

vector<int> v;

int main()
{
    cin >> n >> m;
    int nb = m - 1;
        loop(i, 1, n)
        {
            v.push_back(i);
        }
        int cnt = (m - 1) % n;
        int ans = 0;
        while (v.size())
        {
            cout << v[cnt]; ans++;
            v.erase(v.begin() + cnt);
            if (v.size()>1)
                nb = (m - 1) % v.size();
            else if(v.size() == 1) cnt = 0;
            if (nb == 0) nb = v.size();
            for (int i = 1; i <= nb; i++)
            {
                cnt++;
                if (cnt >= v.size() - 1 && v.size() != 1) cnt %= v.size();
                else if (v.size() == 1) cnt = 0;
            }
            cout << endl;
    }
    return 0;
}