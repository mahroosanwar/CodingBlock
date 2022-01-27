//Pascal Triangle Pattern 3

#include <iostream>
using namespace std;

int main()
{
    int i,j,n,no = 1;
    cin >>n;
    for (i=0; i<n; i++)
    {
        for (j = 0; j<=i; j++)
        if (j==0 || i == 0)
            cout << no << "    ";

        else
        {
            no = no*(i-j+1)/j;
            cout << no <<"    ";
        }
        cout << endl;
    }
    return 0;
}