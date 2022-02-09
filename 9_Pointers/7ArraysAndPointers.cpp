//Arrays And Pointers

#include <iostream>
using namespace std;

int main(){
    int a[] = {1, 2, 3, 4};

    for(int i=0; i<(sizeof(a)/sizeof(int)); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    for(int i=0; i<(sizeof(a)/sizeof(int)); i++){
        cout << *(a + i) << " ";        //a+i gives the address of ith index and with * it gives its value
    }

    cout << endl;


}