// Number is Armstrong Number or Not

#include <iostream>
#include <cmath>
using namespace std;

int numberofDigits(long long int n){
    int order = 0;
    while(n!=0){						//to find the order of number
        n /= 10;
        ++order;
    }
    return order;
}
void is_Armstrong(long long int n){
    int order = numberofDigits(n);
    long long int num = 0;
    long long int temp = n;

    while(temp!=0){						
        int rem = temp % 10;
        num += pow(rem,order);     //condition for Armstrong number
        temp/=10;
    }
    if(n == num){						//check 
        cout << "true"<< endl;
    }
    else{
        cout << "false" << endl;
    }
}

int main(){
    long long int n;
    cin >> n;

    is_Armstrong(n);

    return 0;
}
 


// Take the following as input.

// A number
// Write a function which returns true if the number is an armstrong number and false otherwise, where Armstrong number is defined as follows.

// A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if.

// abcd… = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + ….

// 1634 is an Armstrong number as 1634 = 1^4 + 6^4 + 3^4 + 4^4

// 371 is an Armstrong number as 371 = 3^3 + 7^3 + 1^3

// Input Format
// Single line input containing an integer

// Constraints
// 0 < N < 1000000000

// Output Format
// Print boolean output for each testcase.
// "true" if the given number is an Armstrong Number, else print "false".

// Sample Input
// 371
// Sample Output
// true
// Explanation
// Use functions. Write a function to get check if the number is armstrong number or not. Numbers are armstrong if it is equal to sum of each digit raised to the power of number of digits.
