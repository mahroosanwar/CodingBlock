// Print Hello World Using Function

#include <iostream>
using namespace std;

void HelloWorld(){              //void function not return anything
    cout << "Hello World!" << endl;
}

void Multiply(int a, int b){
    cout << a*b << endl;
}
int main(){

    HelloWorld();           //Call or invoke function

    int a  = 10, b = 20;
    Multiply(a,b);
    cout << endl;
    return 0;
}
