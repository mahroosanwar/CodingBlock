//Fibonacci

#include <iostream>
using namespace std;

int fibo(int n){
    //base case 
    if(n==0 || n==1){
        return n;
    }
    //recursive case
    //nth fibo number = (nth-1)+(nth-2) numb;  its pure assumption (we slove first then see how it's working )

    //find the solution
    return fibo(n-1)+fibo(n-2);
}

int main(){
    int n;
    cin >> n;

    cout << fibo(n) ;

    return 0;
}