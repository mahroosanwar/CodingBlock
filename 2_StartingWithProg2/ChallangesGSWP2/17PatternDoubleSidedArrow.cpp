//Pattern Double Sided Arrow

#include <iostream>
using namespace std;

int main()
{
    int i,j,n;
    cin >> n;

    for (i=0; i<n/2+1; i++)
    {
        for (j=0; j < n-2*i-1; j++)
        {
            cout << "  ";
        }
        for (j=i+1; j>0; j--)
            cout << j << " ";
        for (j=0; j<2*i-1; j++)
            cout << "  ";
        for (j=1; j<=i+1; j++)
            if (i!=0)  
            cout << j << " ";
    cout << endl;
    }
    for (i=n/2-1; i>=0; i--)
    {
        for (j=0; j < n-2*i-1; j++)
        {
            cout << "  ";
        }
        for (j=i+1; j>0; j--)
            cout << j << " ";
        for (j=0; j<2*i-1; j++)
            cout << "  ";
        for (j=1; j<=i+1; j++)
            if (i!=0)   
            cout << j << " ";
    cout << endl;
    }
    return 0;

}