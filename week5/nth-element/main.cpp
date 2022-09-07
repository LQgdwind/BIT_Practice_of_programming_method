#pragma GCC optimize(3,"Ofast","inline")

#define _CRT_SECURE_NO_WARNINGS  
#define loop(i,a,b) for(int i=a;i<=b;i++)  

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int a[1000010]; int s[1000010];

int quickread()
{
    int w = 1, c, ret;
    while ((c = getchar()) > '9' || c < '0') w = (c == '-' ? -1 : 1); ret = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + c - '0';
    return ret * w;
}

int n, query;
int nb=0;

int findk(int l, int r, int k)
{
    while (l != r)
    {
        int i = l - 1;;
        int  j = r + 1;
        int mid = s[(l + r) >> 1];
        while (i < j)
        {
            do i++; while (s[i] < mid);
            do j--; while (s[j] > mid);
            if (i < j)
            {
                nb = s[i];
                s[i] = s[j];
                s[j] = nb;
            }
        }
        int s1 = j - l + 1;
        if (k <= s1)
        {
            r = j;
        }
        else
        {
            l = j + 1;
            k = k - s1;
        }
    }
    if (l == r) return s[l];
}

int main()
{
    //freopen("1.in", "r+", stdin);
    //freopen("1.out", "a+", stdout);
    n = quickread();
    loop(i, 0, n - 1)
    {
        *(a+i) = quickread();
    }
    query = quickread();
    while (query--)
    {
        int t = quickread();
        if (t == 1)
        {
            int mark, value;
            mark = quickread(); value = quickread();
            a[mark] = value;
        }
        else if (t == 2)
        {
            int l, r, k;
            l = quickread(); r = quickread(); k = quickread();
            int inputcnt = 0;
            loop(i, l, r)
            {
                s[inputcnt] = a[i];
                inputcnt++;
            }
            int res = findk(0, inputcnt - 1, k);
            printf("%d\n", res);
        }
    }
}