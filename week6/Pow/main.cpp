#include "iostream"

using namespace std;

typedef long long ll;
int a, b, p;

int myfastpower(int a, int b, int p)
{
    int res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1) res = (ll)a * res % p;
        a = (ll)a * (ll)a % p;
    }
    return res;
}

int main()
{
    cin >> a >> b ;
    p = 1000000007;
    if (b < 0 && a == 1) cout << 1 << endl;
    else if (b < 0 && a == 0) cout << 0 << endl;
    else cout << myfastpower(a, b, p) << endl;
}