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

// Take N as input. For a value of N=7, we wish to draw the following pattern :

//                             1 
//                         2 1   1 2 
//                     3 2 1       1 2 3 
//                 4 3 2 1           1 2 3 4 
//                     3 2 1       1 2 3 
//                         2 1   1 2 
//                             1 
// Input Format
// Take N as input.

// Constraints
// N is odd number.

// Output Format
// Pattern should be printed with a space between every two values.

// Sample Input
// 7
// Sample Output
//             1 
//         2 1   1 2 
//     3 2 1       1 2 3 
// 4 3 2 1           1 2 3 4 
//     3 2 1       1 2 3 
//         2 1   1 2 
//             1 
// Explanation
// Catch the pattern and print it accordingly.
