//wave print column wise from 2D array

#include <iostream>
using namespace std;

void WavePrintColumnWise(int a[][10], int m, int n){
    for(int col = 0; col<n; col++){
        if(col%2 == 0){
            for(int row=0; row<m; row++){
                cout << a[row][col] << ", ";
            }
        }

        else{
            for(int row=m-1; row>=0; row--){
                cout << a[row][col] << ", ";
            }
        }
    }
    cout << "END";
}

int main(){
    int a[10][10];
    int m,n;
    cin >> m >> n;

    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            cin >> a[row][col];
        }
    }

    WavePrintColumnWise(a,m,n);
}