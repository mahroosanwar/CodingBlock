//Print Numbers Pattern

#include <iostream>
using namespace std;

int main()
{
    int row ,i ,N,no;
    cout << "Enter the number of Rows: ";
    cin >> N;

    for (row = 1; row <= N; row = row + 1)
    {
        for (i = 1 ; i <= N-row; i = i + 1)
        {
            cout << ' ';
        }
    no = 1;
    for (i = 1; i <= 2*row-1; i = i + 1 )
    {
        cout << no;
        no = no + 1;
    }
    cout << endl;
    }
    cout <<endl;
    return 0;
}