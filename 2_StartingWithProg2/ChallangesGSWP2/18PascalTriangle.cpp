//Pascal Triangle

#include <iostream>
using namespace std;

int main()
{
    int i,j,n;
    cin >> n;
    for (i = 0; i<n; i++)
    {
        for (j = 0; j<n-i; j++)
        cout << "  ";
        int no = 1;
        for (j=0; j<=i; j++)
        
        if (j==0 || i == 0)
        
            cout << no << "   ";
        
        else
        {
            no = no*(i-j+1)/j;
            cout << no << "   ";
        }
        
        cout << endl; 
    }
    return 0;
}