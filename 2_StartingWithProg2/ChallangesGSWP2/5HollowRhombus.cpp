// Hollow Rhombus Pattern

#include <iostream>
using namespace std;

int main()
{
    int i,j,N;
    cin >> N;
    for (i = 1; i <= N; i++)
    {
        for (j = i; j <= N; j++)
        {
            if(j < N)
            {
                cout << " ";
            }
            else if (j == N)
            {
                cout << "*";
            }
        }
        for (j = 1; j < N -1; j++)
        {
            if(i == 1 || i == N)
            {
                cout << "*";
            }
            else if(i != 1 || i != N)
            {
                cout << " ";
            }
            
        }
        for (j = 1; j <= i; j++)
        {
            if(j > 1)
            {
                cout << " ";
            }
            else if (j == 1)
            {
                cout << "*";
            }
        }
        cout << endl;
       
    }
    return 0;
}

// Given number of rows N, you have to print a Hollow Rhombus. See the output for corresponding given input.

// Input Format
// Single integer N.

// Constraints
// N <= 20

// Output Format
// Print pattern.

// Sample Input
// 5
// Sample Output
//     *****
//    *   *
//   *   *
//  *   *
// *****
// Explanation
// For any input N. First line contains 4 space and then 5 {*} and then the second line contains according to the output format.
