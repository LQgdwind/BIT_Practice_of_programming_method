#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "vector"

int n, m, q, a[1000005];

int cnt;

int find(int x, int n);
int cmp(int i, int x)
{
    if (i > n || i <= 0)
        return -2;
    if (a[i] > x)
        return 1;
    if (a[i] == x)
        return 0;
    return -1;
}

int main()
{
    scanf("%d %d", &n, &m); //读入

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]); //还是读入

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &q);
        int ans = find(q, n);  //看看查找的结果
        printf("%d ", ans); //输出
    }
    printf("\n");
    std::cout << cnt << std::endl;
    return 0;
}
using namespace std;

int binary_lowbound(int l, int r, int ans)
{
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int temp = cmp(mid, ans);
        if (temp == 1 || temp == 0) r = mid;
        else l = mid + 1;
    }
    if (cmp(l, ans) == 0) return l;
    else return -1;
}

int find(int x, int n)
{
    int j = binary_lowbound(1, n, x);
    return j;
}

