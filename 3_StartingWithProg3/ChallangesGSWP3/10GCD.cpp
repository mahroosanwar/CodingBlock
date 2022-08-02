// GCD of Two numbers

#include <iostream>
using namespace std;

int main()
{
    int i,n1,n2,n,largest =0;
    cin >> n1 >> n2;


    // check which is greater for updation in for 
    if (n1>n2)
    {
        n=n2;
    }
    else
    {
        n=n1;
    }
    for ( i= 1; i<=n; i++)                  // n is small of n1 and n2
    {
        if((n1%i)==0 && (n2%i) == 0){       //will get the common factor of n1 and n2
            if(largest<i)                   //greatest common factor 
            {
                largest = i;
            }
        }
        
    }cout << largest << endl;
    
    return 0;

}


// Take the following as input.

// A number (N1)
// A number (N2)
// Write a function which returns the GCD of N1 and N2. Print the value returned.



// Input Format
// Two integers seperated by a new line.

// Constraints
// 0 < N1 < 1000000000
// 0 < N2 < 1000000000

// Output Format
// Output a single integer which is the GCD of the given integers.

// Sample Input
// 16 
// 24
// Sample Output
// 8
// Explanation
// The largest number that divides both N1 and N2 is called the GCD of N1 and N2.
