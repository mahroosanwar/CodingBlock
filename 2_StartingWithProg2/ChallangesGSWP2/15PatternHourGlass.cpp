//Pattern HourGlass 

#include <iostream>
using namespace std;

int main()
{
    int i,j,n;
    cin >> n;

    for (i=0; i<=n; i++)
    {
        for (j=0; j<i; j++)
        {
            cout << "  ";
        }
        for (j=n-i; j>=0; j--)
        {
            cout << j << " ";
        }
        for (j=1; j<=n-i; j++)
            cout <<j<<" ";
        cout << endl;   
    }
    for (i=n; i>0; i--)
    {
        for (j=0; j<i-1; j++)
        {
            cout << "  ";
        }
        for (j=n-i+1; j>=0; j--)
        {
            cout << j << " ";
        }
        for (j=1; j<=n-i+1; j++)
            cout <<j<<" ";
        cout << endl;  
    }
    return 0;
}


// Take N as input. For a value of N=5, we wish to draw the following pattern :

//                           5 4 3 2 1 0 1 2 3 4 5
//                             4 3 2 1 0 1 2 3 4 
//                               3 2 1 0 1 2 3 
//                                 2 1 0 1 2 
//                                   1 0 1 
//                                     0 
//                                   1 0 1 
//                                 2 1 0 1 2 
//                               3 2 1 0 1 2 3 
//                             4 3 2 1 0 1 2 3 4 
//                           5 4 3 2 1 0 1 2 3 4 5
// Input Format
// Take N as input.

// Constraints
// N <= 20

// Output Format
// Pattern should be printed with a space between every two values.

// Sample Input
// 5
// Sample Output
//  5 4 3 2 1 0 1 2 3 4 5
//    4 3 2 1 0 1 2 3 4 
//      3 2 1 0 1 2 3 
//        2 1 0 1 2 
//          1 0 1 
//            0 
//          1 0 1 
//        2 1 0 1 2 
//      3 2 1 0 1 2 3 
//    4 3 2 1 0 1 2 3 4 
//  5 4 3 2 1 0 1 2 3 4 5
