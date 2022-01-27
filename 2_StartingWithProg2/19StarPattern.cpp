//Print Star 
#include <iostream>
using namespace std;

int main()
{
    int N,row,col;
    cout << "Enter Numbers of Rows: ";
    cin >> N;
    for (row = 1; row <= N; row = row + 1)
    {
        for (col = 1; col <=row; col = col + 1)
        {
            cout << "* " ;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}