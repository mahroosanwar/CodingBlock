// LCM of two number

#include <iostream>
using namespace std;

int main()
{
    int n1, n2, i, n, hcf;
    cin >> n1 >> n2;
    if(n1>n2)
    {
        n = n2;
    }
    else{
        n = n1;
    }

    for (i = 1; i <= n; i++)
    {
        if((n1%i) == 0 && (n2%i) == 0)
        {
            hcf = i;
        }   
    }
    cout << (n1*n2)/hcf << endl;            //LCM = (product of numbers)/HCF
    return 0;
}

// Take the following as input.

// A number (N1)
// A number (N2)
// Write a function which returns the LCM of N1 and N2. Print the value returned.

// Input Format
// Constraints
// 0 < N1 < 1000000000 0 < N2 < 1000000000

// Output Format
// Sample Input
// 4 
// 6
// Sample Output
// 12
// Explanation
// The smallest number that is divisible by both N1 and N2 is called the LCM of N1 and N2.
