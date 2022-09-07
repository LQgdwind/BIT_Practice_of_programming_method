/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "vector"
#include "string"


using namespace std;

int numofstudent;
int numoftest;
double usersright_total[1010];
double usersrightrate_total[1010];
int theorder;
double usersright_temp[1010];
double usersrightrate_temp[1010];
string backup;
int cnt0, cnt1;

class Solution {
public:
    Solution(int n, int m)
    {
        numofstudent = n;
        numoftest = m;
        memset(usersrightrate_total, 0, sizeof(usersrightrate_total));
        memset(usersrightrate_temp, 0, sizeof(usersrightrate_temp));
        memset(usersright_total, 0, sizeof(usersright_total));
        memset(usersright_temp, 0, sizeof(usersright_temp));
        theorder = 0;
    }
    int doJudge(string usersAnswer, int lastAnswer)
    {
        if (theorder == 0)
        {
            theorder++; cnt0 = 0; cnt1 = 0;
            for (int i = 0; i < numofstudent; i++)
            {
                backup += usersAnswer[i];
                if (usersAnswer[i] == '0') cnt0++;
                else if (usersAnswer[i] == '1') cnt1++;
            }
            if (cnt0 > cnt1) return 0;
            else if (cnt1 > cnt0)return 1;
            else if (cnt1 == cnt0)
            {
                double x = rand() / (double)(RAND_MAX);
                if (x > 0.5) return 1;
                else if (x < 0.5) return 0;
            }
        }
        else if (theorder > 0 && theorder < 100)
        {
            theorder++; cnt0 = 0; cnt1 = 0;
            for (int i = 0; i < numofstudent; i++)
            {
                if (backup[i] == lastAnswer + '0')
                {
                    usersright_total[i]++;
                }
            }
            for (int i = 0; i < numofstudent; i++)
            {
                usersrightrate_total[i] = usersright_total[i] / ((double)theorder - 1);
            }
            backup.clear();
            double maxofrightrate = 0.0;
            for (int i = 0; i < numofstudent; i++)
            {
                maxofrightrate = max(maxofrightrate, usersrightrate_total[i]);
            }
            for (int i = 0; i < numofstudent; i++)
            {
                backup += usersAnswer[i];
                if (usersrightrate_total[i] > 0.7)
                {
                    if (usersAnswer[i] == '0') cnt0++;
                    else if (usersAnswer[i] == '1') cnt1++;
                }
                else if (usersrightrate_total[i] < 0.15 && theorder>10)
                {
                    if (usersAnswer[i] == '1') cnt0++;
                    else if (usersAnswer[i] == '0') cnt1++;
                }
            }
            double selectstudent = cnt0 + cnt1;
            double doublenumofstudent = (double)numofstudent / 20.0;
            if (selectstudent <= doublenumofstudent && maxofrightrate < 0.8)
            {
                for (int i = 0; i < numofstudent; i++)
                {
                    if (usersrightrate_total[i] > 0.6 && theorder > 10)
                    {
                        if (usersAnswer[i] == '0') cnt0++;
                        else if (usersAnswer[i] == '1') cnt1++;
                    }
                    else if (usersrightrate_total[i] < 0.2 && theorder>10)
                    {
                        if (usersAnswer[i] == '1') cnt0++;
                        else if (usersAnswer[i] == '0') cnt1++;
                    }
                }
            }
            if (cnt0 > cnt1) return 0;
            else if (cnt1 > cnt0)return 1;
            else if (cnt1 == cnt0)
            {
                double x = rand() / (double)(RAND_MAX);
                if (x > 0.5) return 1;
                else if (x < 0.5) return 0;
            }
        }
        else if (theorder >= 100)
        {
            theorder++; cnt0 = 0; cnt1 = 0;
            int theshort = theorder % 100;
            if (theshort == 0)
            {
                theshort = 100;
            }
            for (int i = 0; i < numofstudent; i++)
            {
                if (backup[i] == lastAnswer + '0')
                {
                    usersright_total[i]++;
                    usersright_temp[i]++;
                }
            }
            for (int i = 0; i < numofstudent; i++)
            {
                usersrightrate_total[i] = usersright_total[i] / ((double)theorder - 1);
                usersrightrate_temp[i] = usersright_temp[i] / ((double)theshort);
            }
            backup.clear();
            if (theshort == 100)
            {
                memset(usersright_temp, 0, sizeof(usersright_temp));
            }
            double maxofrightrate_total = 0.0;
            double maxofrightrate_temp = 0.0;
            for (int i = 0; i < numofstudent; i++)
            {
                maxofrightrate_total = max(maxofrightrate_total, usersrightrate_total[i]);
                maxofrightrate_temp = max(maxofrightrate_temp, usersrightrate_temp[i]);
            }
            for (int i = 0; i < numofstudent; i++)
            {
                backup += usersAnswer[i];
                if (theshort > 5)
                {
                    if (maxofrightrate_total >= 0.8)
                    {
                        if (usersrightrate_total[i] > 0.7 && usersrightrate_temp[i] > 0.7 || usersrightrate_total[i] > 0.8 && usersrightrate_temp[i] > 0.6 || usersrightrate_total[i] > 0.6 && usersrightrate_temp[i] > 0.8)
                        {
                            if (usersAnswer[i] == '0') cnt0++;
                            else if (usersAnswer[i] == '1') cnt1++;
                        }
                        else if (usersrightrate_total[i] < 0.2 && usersrightrate_temp[i] < 0.2 || usersrightrate_total[i] < 0.3 && usersrightrate_temp[i] < 0.1 || usersrightrate_total[i] < 0.1 && usersrightrate_temp[i] < 0.3)
                        {
                            if (usersAnswer[i] == '0') cnt1++;
                            else if (usersAnswer[i] == '1') cnt0++;
                        }
                    }
                    if (maxofrightrate_total < 0.8)
                    {
                        if (usersrightrate_total[i] > 0.6 && usersrightrate_temp[i] > 0.7 || usersrightrate_total[i] > 0.8 && usersrightrate_temp[i] > 0.6 || usersrightrate_total[i] > 0.55 && usersrightrate_temp[i] > 0.8)
                        {
                            if (usersAnswer[i] == '0') cnt0++;
                            else if (usersAnswer[i] == '1') cnt1++;
                        }
                        else if (usersrightrate_total[i] < 0.2 && usersrightrate_temp[i] < 0.2 || usersrightrate_total[i] < 0.3 && usersrightrate_temp[i] < 0.1 || usersrightrate_total[i] < 0.1 && usersrightrate_temp[i] < 0.3)
                        {
                            if (usersAnswer[i] == '0') cnt1++;
                            else if (usersAnswer[i] == '1') cnt0++;
                        }
                    }
                }
                else if (theshort <= 5)
                {
                    if (maxofrightrate_total >= 0.8)
                    {
                        if (usersrightrate_total[i] > 0.7)
                        {
                            if (usersAnswer[i] == '0') cnt0++;
                            else if (usersAnswer[i] == '1') cnt1++;
                        }
                        else if (usersrightrate_total[i] < 0.15)
                        {
                            if (usersAnswer[i] == '0') cnt1++;
                            else if (usersAnswer[i] == '1') cnt0++;
                        }
                    }
                    else if (maxofrightrate_total < 0.8)
                    {
                        if (usersrightrate_total[i] > 0.6)
                        {
                            if (usersAnswer[i] == '0') cnt0++;
                            else if (usersAnswer[i] == '1') cnt1++;
                        }
                        else if (usersrightrate_total[i] < 0.15)
                        {
                            if (usersAnswer[i] == '0') cnt1++;
                            else if (usersAnswer[i] == '1') cnt0++;
                        }
                    }
                }
            }
            double selectstudent = cnt0 + cnt1;
            double doublenumofstudent = (double)numofstudent / 30.0;
            if (selectstudent <= doublenumofstudent)
            {
                if (maxofrightrate_total < 0.85)
                {
                    for (int i = 0; i < numofstudent; i++)
                    {
                        if (usersrightrate_temp[i] > 0.7 && theshort > 5)
                        {
                            if (usersAnswer[i] == '0') cnt0++;
                            else if (usersAnswer[i] == '1') cnt1++;
                        }
                        else if (usersrightrate_temp[i] < 0.15 && theshort>10)
                        {
                            if (usersAnswer[i] == '1') cnt0++;
                            else if (usersAnswer[i] == '0') cnt1++;
                        }
                    }
                }
                else if (maxofrightrate_total >= 0.85)
                {
                    for (int i = 0; i < numofstudent; i++)
                    {
                        if (usersrightrate_temp[i] > 0.8 && theshort > 5)
                        {
                            if (usersAnswer[i] == '0') cnt0++;
                            else if (usersAnswer[i] == '1') cnt1++;
                        }
                        else if (usersrightrate_temp[i] < 0.15 && theshort>10)
                        {
                            if (usersAnswer[i] == '1') cnt0++;
                            else if (usersAnswer[i] == '0') cnt1++;
                        }
                    }
                }
            }
            if (cnt0 + cnt1 == 0)
            {
                for (int i = 0; i < numofstudent; i++)
                {
                    if (usersrightrate_temp[i] > 0.6 && theshort > 10 || usersrightrate_total[i] > 0.55 && usersrightrate_temp[i] > 0.5)
                    {
                        if (usersAnswer[i] == '0') cnt0++;
                        else if (usersAnswer[i] == '1') cnt1++;
                    }
                }
            }
            if (cnt0 > cnt1) return 0;
            else if (cnt1 > cnt0)return 1;
            else if (cnt1 == cnt0)
            {
                double x = rand() / (double)(RAND_MAX);
                if (x > 0.5) return 1;
                else if (x < 0.5) return 0;
            }
        }
    }
};


vector<int> sresult;
int main()
{
    int n, m;
    freopen("1.in", "r+", stdin);
    freopen("1.out", "a+", stdout);

    scanf("%d%d", &n, &m);
    vector<string> usersAnswers;
    vector<int> answers;
    for (int i = 0; i < m; i++) {
        char s[25555];
        int ans;
        scanf("%s%d", s, &ans);
        usersAnswers.push_back(s);
        answers.push_back(ans);
    }

    Solution yourSolution(n, m);
    for (int i = 0; i < m; i++) {
        int result = yourSolution.doJudge(usersAnswers[i], i == 0 ? -1 : answers[i - 1]);
        //printf("%d\n", result);
        sresult.push_back(result);
    }
    int dadui = 0;
    for (int i = 0; i < m; i++)
    {
        if (sresult[i] == answers[i]) dadui++;
    }
    double ratedui = 100.0 * (double)dadui / (double)m;
    cout << ratedui << "%" << endl;
    return 0;
}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */