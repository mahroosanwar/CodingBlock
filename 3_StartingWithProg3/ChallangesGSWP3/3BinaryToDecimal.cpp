//Binary to Decimal

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,N,num=0,place= 0;
    cin >> n;
    while(n!=0)
    {
        int rem = n%10;       //rem is remainder
        num = num + rem*pow(2,place);
        n/=10;
        place++;
    }
    cout << num << endl;
    return 0;
}

// Take N (number in binary format). Write a function that converts it to decimal format and Print the value returned.

// Input Format
// Constraints
// 0 < N <= 1000000000

// Output Format
// Sample Input
// 101010
// Sample Output
// 42
// Explanation
// For binary number fedcba , Decimal number = f * 25 + e * 24 + d * 23 + …..+ a * 20.
