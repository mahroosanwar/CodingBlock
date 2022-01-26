//Pattern Rohmbus

#include <iostream>
using namespace std;
int main()
{
    int i,j,n;
    cin >> n;

    for (i = 0; i<n; i++)
    {
        for(j = 0; j<n-i-1; j++)
        cout << "     ";
        
        for(j = 0; j<i+1; j++)
        cout << i+j+1 << "    ";

        for(j = 0; j<i; j++)
        cout << 2*i-j << "    ";

    cout << endl;
    }

    for(i = n-2; i>=0; i--)
    {
        for(j = 0; j<n-i-1; j++)
        cout << "     ";
        
        for(j = 0; j<i+1; j++)
        cout << i+j+1 << "    ";

        for(j = 0; j<i; j++)
        cout << 2*i-j << "    ";
    cout << endl;
    }
    return 0;
}