//Using New and Delete Operators

#include <iostream>
using namespace std;

int main(){

    //static Allocation (allocation  + delocation done by the compiler --> so no need to delete)
    int b[100];
    // int b[100] = {0};            // starting all with zeroes

    cout << sizeof(b) << endl;      //here b represent the entire array
    cout << b << endl;     //comes from the symbol table
    //here b cann't be overwritten --> bcz it's the part of Read Only Memory
    
    //Dynamic Allocation (on the fly - in run time)
    int n; cin >> n;
    int *a = new int[n];
    // int *a = new int[n]{0};      --> starting with all zeroes
    cout << sizeof(a) << endl;      //here a represent starting of add of a
    cout << b << endl;              // comes from the variable that is created inside the static memory
    //so this can be over written
    //a  = new char[30]

    for(int i = 0; i<n; i++){
        cin >> a[i];
        cout << a[i] <<  " ";
    }


    //Free up the space to avoid the memory leak
    delete [] a;

    return 0;
}

