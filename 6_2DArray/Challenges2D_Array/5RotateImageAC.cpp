//Rotate Image(2D array)Anti clock Wise

#include <iostream>
using namespace std;
void RotateImage(int a[][100], int n){
    //first swap the column
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n/2; col++){
            swap(a[row][col], a[row][n-1-col]);
        }
    }

    //then Transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i<j){
                swap(a[i][j], a[j][i]);
            }
        }
    }
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            cout << a[row][col] << " "; 
        }
        cout << endl;
    }
}
int main(){
    int a[100][100];
    int n;
    cin >> n;

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            cin >> a[row][col]; 
        }
    }

    RotateImage(a,n);

    cout << endl;
    return 0;
}