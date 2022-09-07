#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "iostream"
#include "string"
#include "cstring"
#include "cstdio"
#include "cstdlib"


using namespace std;

int getNumberOfInfestor();
// you should finish this
const int POPULATION = 1000000;

int nb = 0;
bool test(int y)
{
    nb++;
    if (y < 1 || y > POPULATION) {
        printf("error");
        return false;
    }
    // result = 随机从POPULATION人中抽取y人核酸检测的结果。
    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    long long seed;
    scanf("%lld", &seed);
    int result = getNumberOfInfestor();
    printf("%d\n", result);
    cout << nb << endl;
    // 输出你的询问记录
    return 0;
}


int getNumberOfInfestor() 
{
    int t = 100000;
    bool judge;
    int o = 0;
    for (int j = 1; j <= 10; j++)
    {
        int cnt = 0;
        for (int i = 1; i <= 5; i++)
        {
            judge = test(t);
            if (judge) cnt++;
        }
        if (cnt < 3)
        {
            o = 10-j;
            break;
        }
        if (j <= 5) t = t / 2;
        else if (j > 5) t = t / 4;
    }
    int restcnt = 0;
    int restloop = o / 5;
    int tempi = 1;
    while(tempi<=restloop)
    {
        tempi++;
        for (int j = 1; j <= 5; j++)
        {
            judge = test(t);
            if (judge) restcnt++;
        }
        if (restcnt > 3) t = t / 2;
        else if (restcnt <= 1) t = t * 2;
    }
    int res = 1000000 / t;
    return res;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */