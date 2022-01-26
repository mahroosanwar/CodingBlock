//Pattern No. Ladder

#include <iostream>
using namespace std;

int main()
{
    int i,j,N,no = 0;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            no++;
            cout << no << "    ";
        }
        cout << endl;
    }
    return 0;

}