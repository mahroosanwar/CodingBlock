//Returning Dynamic Arrays

#include <iostream>
using namespace std;

int* fun() {            //it return address (--> gives pointer value)
    int *a = new int[5];      //dynamic array
    a[0] = 11;
    a[1] = 2;
    cout << a << endl;          //xyz --> give some add.

    cout << a[0] << endl;       // 11

    return a;       
}

int main(){
    int *b = fun();                 //fun(xyz) will be stored in b and a will be destroyed after fun call

    cout << b << endl;      // xyz

    cout << b[0] << endl;   // 11

    //clear array (delete dynainc memory)
    delete [] b;
    return 0;
}

