// Returning Local Arrays

#include <iostream>
using namespace std;

int* fun() {            //it return address (--> gives pointer value)
    int a[] = {1,2,3,4,5};      //static array

    cout << a << endl;          //xyz --> give some add.

    cout << a[0] << endl;       // 1

    return a;       
}

int main(){
    int *b = fun();

    cout << b << endl;      //xyz

    cout << b[0] << endl;   //return garbage bcz static array a[] is cleared from memory

    return 0;
}

