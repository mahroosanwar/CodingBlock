// Mirror star Pattern (Pattern 5)

#include <iostream>
using namespace std;

int main()
{
    int i,j,N,n;
    cin >> N;
    n = (N + 1)/2;
    for (i = 1; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            cout << "  ";
        }
        for (j = 1; j < i; j++)
        {
            cout << "* ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < i; j++)
        {
            cout << "  ";
        }
        for (j = i; j < n; j++)
        {
            cout << "* ";
        }
        for (j = i; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}