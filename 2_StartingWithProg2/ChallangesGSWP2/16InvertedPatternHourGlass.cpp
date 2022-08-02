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

// Take N as input. For a value of N=5, we wish to draw the following pattern :

//              5                   5 
//              5 4               4 5 
//              5 4 3           3 4 5 
//              5 4 3 2       2 3 4 5 
//              5 4 3 2 1   1 2 3 4 5 
//              5 4 3 2 1 0 1 2 3 4 5 
//              5 4 3 2 1   1 2 3 4 5 
//              5 4 3 2       2 3 4 5 
//              5 4 3           3 4 5 
//              5 4               4 5 
//              5                   5 
// Input Format
// Take N as input.

// Constraints
// Output Format
// Pattern should be printed with a space between every two values.

// Sample Input
// 5
// Sample Output
// 5                   5 
// 5 4               4 5 
// 5 4 3           3 4 5 
// 5 4 3 2       2 3 4 5 
// 5 4 3 2 1   1 2 3 4 5 
// 5 4 3 2 1 0 1 2 3 4 5 
// 5 4 3 2 1   1 2 3 4 5 
// 5 4 3 2       2 3 4 5 
// 5 4 3           3 4 5 
// 5 4               4 5 
// 5                   5 
