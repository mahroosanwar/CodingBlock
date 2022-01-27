// Fibonacci Sequence

#include <iostream>
using namespace std;

int fibo(int n)
{   int a=0, b=1, c;
    if(n==1){
        return 1;           //0 is 1st term
    }
    else if(n==2){                  //1 is 2nd term
        return 2;
    }
    else{
        for(int i = 1; i<=n; i++ ){
            c = a + b;
            a = b;
            b = c;
             
        }
        return c;
    }
    
}

int main(){
    int n;
    cin >>n;

    cout << fibo(n);

    cout << endl;
    return 0;
}