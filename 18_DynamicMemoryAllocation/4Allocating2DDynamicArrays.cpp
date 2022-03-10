//Allocating 2D Dynamic Arrays

#include <iostream>
using namespace std;

int main(){

    int **arr;
    int r, c;
    cin >> r >> c;
    
    arr = new int *[r];      //r --> no. of rows, create the array of row heads

    for(int i=0; i<r; i++){
        arr[i] = new int[c];     //c--> no . of cloumn, create the 2D array 
    }

    //take the input and print the elements
    int val = 1;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            arr[i][j] = val;
            val++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}