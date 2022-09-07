/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */
#define _CRT_SECURE_NO_WARNINGS  

#include <stdio.h>
#include <string.h>

void plus(const char* a, const char* b, char* c);
void minus(const char* a, const char* b, char* c);
void multiply(const char* a, const char* b, char* c);

int main()
{
    static char a[100005];
    static char b[100005];
    static char c[200005];
    static char s[2];

    while (scanf("%s %s %s", a, s, b) == 3) {
        if (s[0] == '+') {
            plus(a, b, c);
        }
        else if (s[0] == '-') {
            minus(a, b, c);
        }
        else if (s[0] == '*') {
            multiply(a, b, c);
        }
        printf("%s\n", c);
    }

    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
#include "string.h"
#include "stdlib.h"
char a0[100005];
char b0[100005];
char a1[100005];
char b1[100005];
int x[100005]; int y[100005]; int z[200005];
int flag = 0;

void init()
{
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(z, 0, sizeof(z));
}
void judge(const char* a, const char* b)
{
    int ia=0, ib=0;
    strcpy(a0, a);
    strcpy(b0, b);
    for (ia = 0; ia <= strlen(a0) - 1; ia++)
    {
        if (a0[ia] != '0') break;
    }
    for (ib = 0; ib <= strlen(b0) - 1; ib++)
    {
        if (b0[ib] != '0') break;
    }
    if (a0[strlen(a0) - 1] == '0') ia = 0;
    if (b0[strlen(b0) - 1] == '0') ib = 0;
    if (ia != 0)
    {
        for (int i = 0; i <= strlen(a0) - ia - 1; i++)
        {
            a0[i] = a0[i + ia];
        }
        a0[strlen(a0) - ia] = '\0';
    }
    if (ib != 0)
    {
        for (int i = 0; i <= strlen(b0) - ib - 1; i++)
        {
            b0[i] = b0[i + ib];
        }
        b0[strlen(b0) - ib] = '\0';
    }
    if (strlen(a0) < strlen(b0))
    {
        strcpy(a1, b0);
        strcpy(b1, a0);
        flag = 1;
    }
    else if (strlen(a0) == strlen(b0))
    {
        if (strcmp(a0, b0) < 0)
        {
            strcpy(a1, b0); strcpy(b1, a0);
            flag = 1;
        }
        else if (strcmp(a0, b0) >= 0)
        {
            strcpy(a1, a0); strcpy(b1, b0);
        }
    }
    else if (strlen(a0) > strlen(b0))
    {
        strcpy(a1, a0); strcpy(b1, b0);
    }
}
void plus(const char* a, const char* b, char* c)
{
    flag = 0;
    int cntx = 0; int cnty = 0; int cntz = 0;
    init(); judge(a, b);
    for (int i = strlen(a1) - 1; i >= 0; i--)
    {
        x[cntx] = a1[i] - '0';
        cntx++;
    }
    for (int i = strlen(b1) - 1; i >= 0; i--)
    {
        y[cnty] = b1[i] - '0';
        cnty++;
    }
    int t = 0;
    for (int i = 0; i < strlen(a1) || i < strlen(b1); i++)
    {
        if (i < strlen(a1)) t += x[i];
        if (i < strlen(b1)) t += y[i];
        z[cntz] = (t % 10);
        cntz++;
        t = t / 10;
    }
    if (t != 0)
    {
        z[cntz] = t;
    }
    else cntz--;

    int num = 0;
    for (int i = cntz; i >= 0; i--)
    {
        c[num] = (char)('0' + z[i]);
        num++;
    }
    c[num] = '\0';
}
void minus(const char* a, const char* b, char* c)
{
    flag = 0;
    int cntx = 0; int cnty = 0; int cntz = 0;
    init(); judge(a, b);
    for (int i = strlen(a1) - 1; i >= 0; i--)
    {
        x[cntx] = a1[i] - '0';
        cntx++;
    }
    for (int i = strlen(b1) - 1; i >= 0; i--)
    {
        y[cnty] = b1[i] - '0';
        cnty++;
    }
    int t = 0;
    for (int i = 0; i < strlen(a1); i++)
    {
        t = x[i] - t;
        if (i < strlen(b1)) t -= y[i];
        z[cntz] = ((t + 10) % 10);
        cntz++;
        if (t < 0) t = 1;
        else t = 0;
    }
    while (cntz > 1 && z[cntz - 1] == 0) cntz--;
    int num = 0;
    if (flag == 1)
    {
        c[num] = '-';
        num++;
    }
    for (int i = cntz - 1; i >= 0; i--)
    {
        c[num] = (char)('0' + z[i]);
        num++;
    }
    c[num] = '\0';
}
void multiply(const char* a, const char* b, char* c)
{
    flag = 0;
    int cntx = 0; int cnty = 0;
    init(); judge(a, b);
    for (int i = strlen(a1) - 1; i >= 0; i--)
    {
        x[cntx] = a1[i] - '0';
        cntx++;
    }
    for (int i = strlen(b1) - 1; i >= 0; i--)
    {
        y[cnty] = b1[i] - '0';
        cnty++;
    }
    int t = 0;
    for (int i = 0; i < strlen(a1); i++)
        for (int j = 0; j < strlen(b1); j++)
        {
            z[i + j] += x[i] * y[j];
            z[i + j + 1] += z[i + j] / 10;
            z[i + j] %= 10;
        }
    int cntz = strlen(a1) + strlen(b1) - 1;
    while (z[cntz] == 0 && cntz > 0) cntz--;
    int num = 0;
    for (int i = cntz; i >= 0; i--)
    {
        c[num] = (char)('0' + z[i]);
        num++;
    }
    c[num] = '\0';
}
