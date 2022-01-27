// Write A programm for Rotate image(2D Array)

#include <iostream>
using namespace std;

void RotateImage(int a[][100], int n){
    //For Reverse
    for(int row = 0; row<n; row++){
        int sc = 0, ec = n-1;
        while(sc<ec){
            swap(a[row][sc], a[row][ec]);
            sc++;
            ec--;
        }
    }
    //For Transpose
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i<j){
                swap(a[i][j], a[j][i]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int a[100][100];
    int n;
    cin >> n;
    int val = 1;
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            a[row][col] = val;
            val++;
        }
    }

    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            cout << a[row][col] << " ";
        }
        cout << endl;
    }
     cout << endl;
    RotateImage(a,n);
    
    cout << endl;
    return 0;
}