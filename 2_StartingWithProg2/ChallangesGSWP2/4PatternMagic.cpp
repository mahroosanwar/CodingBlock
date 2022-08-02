// WAP for a hollow diamond looking pattern for a given number N.

#include <iostream>
using namespace std;

int main()
{
    int i,j,N;
    cin >> N;
    for (i = 1; i < N; i++)
    {
        for (j = i; j <= N; j++)
        {
            cout << "*";
        }
        for (j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (j = i; j <= N; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (j = i; j < N; j++)
        {
            cout << " ";
        }
        for (j = i; j < N; j++)
        {
            cout << " ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

// You will be given a number N. You have to code a hollow diamond looking pattern.

// The output for N=5 is given in the following image.

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// **      **
// ***    ***
// ****  ****
// **********

// Screen Shot 2016-06-09 at 2.47.18 pm.png

// Input Format
// The input has only one single integer N.

// Constraints
// Output Format
// Output the given pattern.

// Sample Input
// Sample Output
// Explanation
// Write a code to print above given pattern. No space between any two characters.
