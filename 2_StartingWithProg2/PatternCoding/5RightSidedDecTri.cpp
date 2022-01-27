// Right Sided Decreasing Triangle
#include <iostream>
using namespace std;

int main()
{
    int i,j,N;
    cin >> N;
    for (i = 1; i<=N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << "  ";
        }
        for (j = i; j <= N; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}