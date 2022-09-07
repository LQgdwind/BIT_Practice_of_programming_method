#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include<iostream>
#include<string>

using namespace std;
string s[25];
int n;

int* SpellNum(int);

int cnt = 0;
int cmp(int i, int j) {
    cnt++;
    if (i <= 0 || i > n || j <= 0 || j > n)
        return -2;
    return s[i] + s[j] > s[j] + s[i];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    int* index = SpellNum(n);
    for (int i = 1; i <= n; ++i)
        cout << s[index[i]];
    cout << endl;
    cout << cnt << endl;
    return 0;
}

#include <vector>
#include <algorithm>


int* SpellNum(int n)
{
    vector<int> temp;
    for (int i = 1; i <= n; i++)
        temp.emplace_back(i);
    sort(temp.begin(), temp.end(), cmp);
    int* ans = (int*)malloc(200);
    for (int i = 1; i <= n; i++) ans[i] = *(temp.begin() + i - 1);
    return ans;
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */