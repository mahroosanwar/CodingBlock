// Sum of the ODD and EVEN placed Digits

#include <iostream>
using namespace std;

int main()
{
    int n,sum=0;
    cin >> n;
    int n1 =n;              // take n1 = n so it can be use as it's previous(original) value
    while(n!=0)
    {
        int rem=n%10;
        sum  = sum + rem;
        n = n/100;
        
    }
    cout << sum << endl;

    sum = 0;
    while (n1!=0)               
    {
        n1 =n1/10;      //make number even place to once place 
                        //to get the remainder from %
        int rem = n1%10;
        sum = sum + rem;
        n1 = n1/10;
    }

    cout << sum << endl;
    return 0;
}

// Take N as input. Print the sum of its odd placed digits and sum of its even placed digits.

// Input Format
// Constraints
// 0 < N <= 1000000000

// Output Format
// Sample Input
// 2635
// Sample Output
// 11
// 5
// Explanation
// 5 is present at 1st position, 3 is present at 2nd position, 6 is present at 3rd position and 2 is present at 4th position.

// Sum of odd placed digits on first line. 5 and 6 are placed at odd position. Hence odd place sum is 5+6=11

// Sum of even placed digits on second line. 3 and 2 are placed at even position. Hence even place sum is 3+2=5
