//Forward Declaration Path

#include <iostream>
using namespace std;

int Multiply(int, int);

int main(){
    
    int a = 10, b = 20;
    int ans  = Multiply(a,b);       //store in bucket
    cout << ans+100 << endl;

    return 0;
}
int Multiply(int a, int b){
    int p  = a*b;
    return p;
}
