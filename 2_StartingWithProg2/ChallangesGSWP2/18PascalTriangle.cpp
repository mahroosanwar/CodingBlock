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

// Given an integer N, print Pascal Triangle upto N rows. 

//           1
//         1   1
//       1   2   1
//     1   3   3   1
//   1   4   6   4   1

// Input Format
// Single integer N.

// Constraints
// N <= 10

// Output Format
// Print pascal triangle.

// Sample Input
// 4
// Sample Output
//        1
//      1   1
//    1   2   1
//  1   3   3   1
// Explanation
// Last row has one " "
