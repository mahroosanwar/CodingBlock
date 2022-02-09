//Pointers Introduction

#include <iostream>
#include <string>
using namespace std;

int main(){
    int a = 10;
    int*aptr = &a;

    float f = 10.11;
    float*fptr = &f;
    
    // t bucket_name: t: int, float, char, bool, double
    // t *pointer_name;

    cout << &a << endl;
    cout << aptr << endl;

    cout << &f << endl;
    cout << fptr << endl;

    return 0;
}