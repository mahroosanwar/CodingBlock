//Arrays And Pointers

#include <iostream>
using namespace std;

void PrintArray(int *a, int n){

    cout << "Inside Function: " << endl;     
    for(int i=0; i< 4; i++){
        cout << *(a + i) << " ";
    }
    cout << endl;    
}
int main(){
    int a[] = {1, 2, 3, 4};

    for(int i=0; i<(sizeof(a)/sizeof(int)); i++){
        cout << a[i] << " ";
    }
    cout << endl;

    PrintArray(a, 4);
    
    return 0;
}