// Address of Operstor

#include <iostream>
using namespace std;

int main(){

    int a = 10;
    float b = 10.11;

    cout << a << endl;
    cout << &a << endl;   // &bucket _nane for address

    cout << b << endl;
    cout << &b << endl;

    char ch = 'A';
    cout << ch << endl;  //print character
    cout << &ch << endl;    // print address

    int arr[] = {1, 2, 3, 4};
    cout << arr << endl;  // this print the address for int datatype but for char array works differently

    char ch_arr[6] = "hello";
    cout << ch_arr << endl;  //it prints the the char insted of address 

    return 0;
}
