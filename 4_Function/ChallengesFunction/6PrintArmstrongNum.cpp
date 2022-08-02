// Print Armstrong Number N1 to N2

#include <iostream>
#include <cmath>
using namespace std;

int numberofDigits(int n){
    int order = 0;
    while(n!=0){						//to find the order of number
        n /= 10;
        ++order;
    }
    return order;
}
int is_Armstrong(int n){
    int order = numberofDigits(n);
    int num = 0;
    int temp = n;

    while(temp!=0){						
        int rem = temp % 10;
        num += pow(rem,order);     //condition for Armstrong number
        temp/=10;
    }
    if(n == num){						//check 
        num = n;
        cout << num << endl;        // return Value
    }
    return num;
}

int PrintAllNum(int N1, int N2){
    int i;
    for(i = N1; i<=N2; i++){        // call numbeer N1 to N2
        is_Armstrong(i); 
    }
    return i;
}

int main(){
    int N1, N2;
    cin >> N1 >> N2;

    PrintAllNum(N1,N2);

    return 0;
}
 

// Take the following as input.

// A number (N1)
// A number (N2)
// Write a function which prints all armstrong numbers between N1 and N2 (inclusive).

// 371 is an Armstrong number as 371 = 3^3 + 7^3 + 1^3

// Input Format
// Constraints
// 0 < N1 < 100 N1 < N2 < 10000

// Output Format
// Sample Input
// 400
// 1000
// Sample Output
// 407
// Explanation
// Each number in output is in separate line.
