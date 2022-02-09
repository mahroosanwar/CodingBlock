//Character pointer

#include <iostream>
using namespace std;

int main(){
    char ch = 'A';
    char *chptr = &ch;

    cout << &ch << endl;   //not give the address but the value of ch till null 
    cout << chptr << endl; //same for this

    char a[] = "Hello";
    cout << a << endl;      


    // give the address of chptr but we fool this typecasting 
    //it print the value stored in this pointer (float* , void* do same work)
    cout << (int*)chptr << endl;        

    return 0;
}