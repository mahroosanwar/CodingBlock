//Decimal To Octal

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,num=0,place = 0;
    cin >> n;
    while(n!=0)
    {
        int rem = n % 8;
        num = num + rem*pow(10,place);
        place++;
        n/=8; 
    }
    cout << num << endl;
    return 0;
}

// Take N (number in decimal format). Write a function that converts it to octal format. Print the value returned.

// Input Format
// Constraints
// 0 < N <= 1000000000

// Output Format
// Sample Input
// 63
// Sample Output
// 77
// Explanation
// Both input and output are integers
