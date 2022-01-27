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