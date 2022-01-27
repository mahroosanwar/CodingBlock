//Reverse Pattern HourGlass

#include <iostream>
using namespace std;

int main()
{
    int i,j,n;
    cin >> n;
    for (i=0; i<=n; i++)
    {
        for (j=n; j>=n-i; j--)
        {
            cout <<j<<" ";
        }
        for (j=0; j<2*(n-i)-1; j++)
            cout << "  ";

        for(j=n-i;j<=n;j++)
        {
            if(j!=0)
            cout<<j<<" ";
        }
    cout << endl;
    }
    for (i=n-1; i>=0; i--)
    {
        for (j=n; j>=n-i; j--)
        {
            cout <<j<<" ";
        }
        for (j=0; j<2*(n-i)-1; j++)
            cout << "  ";
        
        for (j=n-i; j<=n; j++)
            cout << j << " ";
    cout << endl;
    }
    return 0;
    
}