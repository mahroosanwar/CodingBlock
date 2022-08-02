// Von Neuman Loves Binary

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i<N; i++)
    {
        int no;
        cin >> no;
        int num = 0,place = 0;
        while(no!=0)
        {
            
            int rem = no%10;     //Gives Remainder
            num = num + rem*pow(2,place);
            place++;
            no = no/10;
        }
        cout << num << endl;
    }
    return 0;
}

// Given a binary number ,help Von Neuman to find out its decimal representation. For eg 000111 in binary is 7 in decimal.

// Input Format
// The first line contains N , the number of binary numbers. Next N lines contain N integers each representing binary represenation of number.

// Constraints
// N<=1000 Digits in binary representation is <=16.

// Output Format
// N lines,each containing a decimal equivalent of the binary number.

// Sample Input
// 4
// 101
// 1111
// 00110
// 111111
// Sample Output
// 5
// 15
// 6
// 63
// Explanation
// For binary number fedcba , Decimal number = f * 25 + e * 24 + d * 23 + …..+ a * 20.
