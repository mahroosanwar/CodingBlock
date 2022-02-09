//Dereference Operator (*)

#include <iostream>
using namespace std;

int main(){
    int x = 10;
    int *y;
    y = &x;

    cout << "y is: " << y << endl;
    cout << "&x is: " << &x << endl;

    cout << "&y is: " << &y << endl;
    cout << "*(&x): " << *(&x) << endl;
    cout << "&(*y): " << &(*y) << endl;

    //it will move to the next adjecent bucket that is free 
    //and int type occupies 4 bytes of memory
    //(eg. iof address of x is 100 the &x=1 become 104) 
    cout << "&x + 1: " << &x + 1 << endl;
    //this also do same   
    cout << "y + 1: " << y + 1 << endl;     
    cout << "*y + 1: " << *y + 1 << endl;
    cout << "*(&y): " << *(&y) << endl;

    return 0;
}