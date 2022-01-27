// Replace all zero by 5

#include <iostream>
#include <cmath>
using namespace std;

long long int replace(long long int n){
    long long int rem, new_num = 0, place = 0;
    
    if(n==0){
        n=5;
    }
    while(n!=0){
        rem = n%10;

        if(rem==0){
            rem = 5;
        }

    n/=10;
    new_num = new_num + rem*pow(10,place);
    place++;

    }
    return new_num;
}

int main(){
    long long int n;
    cin >>n;
    cout << replace(n);

    cout << endl;
    return 0;
}