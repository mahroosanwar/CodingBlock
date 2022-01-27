// Square Pattern

#include <iostream>
using namespace std;

int main()
{
    int i,j,N;
    cin >> N;
    for (i = 1; i <= N ; i++)
    {
        for (j = 1; j<=N; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
     return 0;
}
