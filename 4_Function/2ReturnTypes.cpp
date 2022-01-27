//Understanding Return Types

#include <iostream>
using namespace std;

int Multiply(int a, int b){
    int p  = a*b;
    return p;
}

float MultiplyFloat(float a, float b){
    return a*b;
}

int main(){
    int a = 10, b = 20;
    int ans  = Multiply(a,b);       //store in bucket
    cout << ans+100 << endl;

    float x = 10.1, y = 10.11;
    float z=MultiplyFloat(x,y);
    cout << z;

    cout << endl;
    return 0;
}