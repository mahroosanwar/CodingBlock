// WAP to check the Boston Number

#include <iostream>
using namespace std;

int SumOfDigit(int n){
    int sum = 0;
    while(n!=0){
        int rem = n%10;
        sum+=rem;
        n/=10;
    }
    return sum;
}

int prime_factor(int n){

    int sum = 0;
    for(int i = 2; i*i<=n; i++){
        while(n%i==0){
            n/=i;
            sum+=SumOfDigit(i);
        }
    }
    
    if(sum == 0){
        return sum;
    }
    if(n>1){
        sum+=SumOfDigit(n);
    }

    return sum;
}

void Boston_num(int n){
    int sumn, sumPrime;
    sumn = SumOfDigit(n);
    sumPrime = prime_factor(n);

    if(sumPrime == sumn){
        cout << 1;
    }
    else{
        cout << 0;
    }
}


int main(){
    
    int n;
    cin >> n;
    Boston_num(n);
    cout << endl;
    return 0;
}


// A Boston number is a composite number, the sum of whose digits is the sum of the digits of its prime factors obtained as a result of prime factorization (excluding 1 ). The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7. Write a program to check whether a given integer is a Boston number.

// Input Format
// There will be only one line of input:N , the number which needs to be checked.

// Constraints
// 1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)

// Output Format
// 1 if the number is a Boston number. 0 if the number is a not Boston number.

// Sample Input
// 378
// Sample Output
// 1
// Explanation
// Self Explanatory
