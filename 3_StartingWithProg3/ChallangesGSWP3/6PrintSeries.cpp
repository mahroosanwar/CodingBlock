// Print Series

#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    for (int i = 1; i <= n1; i++)
    {
        int num = 3*i + 2;
        if((num%n2)!= 0)
        {
            cout << num << endl;
        }
        else{
            n1++;           //it increase n1 as many times as num%2 == 0 
        }
    }
    return 0;
}

// Take the following as input.

// A number (N1)
// A number (N2)
// Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2.

// Input Format
// Constraints
// 0 < N1 < 100 0 < N2 < 100

// Output Format
// Sample Input
// 10 
// 4
// Sample Output
// 5 
// 11 
// 14 
// 17 
// 23 
// 26 
// 29 
// 35 
// 38 
// 41
// Explanation
// The output will've N1 terms which are not divisible by N2.
