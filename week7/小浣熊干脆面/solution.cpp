#include "bits/stdc++.h"  
using namespace std;
const int N = 1e6 + 10; int mark[N]; int n, m; deque<int> q; int a[N]; int st, ed;
inline void frontchange()
{
    while (true)
    {
        int temp = q.front();
        if (mark[temp] > 1)
        {
            q.pop_front();
            mark[temp]--, st++;
        }
        else if (mark[temp] == 1) break;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        q.push_back(a[i]);
        mark[a[i]]++;
    }
    st = 0, ed = n - 1;
    while (true)
    {
        int temp = q.back();
        if (mark[temp] > 1)
        {
            q.pop_back();
            mark[temp]--, ed--;
        }
        else if (mark[temp] == 1)break;
    }
    frontchange();
    int ans = ed - st + 1;
    for (int i = ed +1; i < n; i++)
    {
        q.push_back(a[i]), ed++;
        mark[a[i]]++;
        frontchange();
        ans = min(ans, ed - st + 1);
    }
    cout << ans << endl;
}