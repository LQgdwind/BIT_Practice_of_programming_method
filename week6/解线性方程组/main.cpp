#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
using namespace std;

const int N = 120;
const double eps = 1e-6;

double matrix[N][N];
int n;

double myabs(double x)
{
    if (x > 0) return x;
    else return -x;
}
bool gauss()
{
    int col = 0; 
    int row = 0;
    int t = 0;
    for (; col < n; col++)
    {
        t = row;
        loop(i,row,n-1) 
        {
            if (myabs(matrix[i][col]) > myabs(matrix[t][col]))
            {
                t = i;
            }
        }
        if (myabs(matrix[t][col]) < eps) continue;
        loop(i,col,n)
        {
            swap(matrix[t][i], matrix[row][i]);
        }
        for (int i = n; i >= col; i--)
        {
            matrix[row][i] /= matrix[row][col];
        }
        loop(i,row+1,n-1)      
        {
            if (myabs(matrix[i][col]) > eps)
            {
                for (int j = n; j >= col; j--)
                {
                    matrix[i][j] = matrix[i][j] -matrix[row][j] * matrix[i][col];
                }
            }
        }
        row = row + 1;
    }
    if (row < n)
    {
        return false;
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            loop(j,i+1,n-1)
            {
                matrix[i][n] = matrix[i][n]- matrix[i][j] * matrix[j][n];
            }
        }
        return true; 
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    if (gauss())
    {
        for (int i = 0; i < n; i++)
        {
            cout << matrix[i][n] << endl;
        }
    }
    else cout << "No Solution" << endl;
    return 0;
}