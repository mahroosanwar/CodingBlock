//Bubble sort using pointer

#include <iostream>
using namespace std;

void PrintArray(int *a, int n){
    for(int i=0; i < n; i++){
        cout << *(a+i) << " ";
    }
    cout << endl;
}

void Bubblesort(int *a, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(*(a+j) > *(a+j+1)){
                swap(*(a+j), *(a+j+1));
            }
        }
    }
}
int main(){
    int a[] = {6, 4, 2, 5, 3, 1};
    int n = sizeof(a)/sizeof(int);

    cout << "Before Sorting: " << endl;
    PrintArray(a,n);
    Bubblesort(a,n);
    cout << "After Sorting: " << endl;
    PrintArray(a,n);
    return 0;
}