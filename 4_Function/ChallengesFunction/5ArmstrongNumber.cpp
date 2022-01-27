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
 