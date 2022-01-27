// passing 2d Array in function

#include <iostream>
using namespace std;

void WavePrint(int a[][5], int n, int m){
    for(int col=0; col<m; col++){
        if(col%2 == 0){
            for(int row = 0; row<n; row++){
                cout << a[row][col] << " ";
            }
        }
        else{
            for(int row=n-1; row>=0; row--){
                cout << a[row][col] << " ";
            }
        }
    }
    cout << endl;
}

int main(){
    int n=4,m=5;
    int val = 1;
    int a[4][5];
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            a[row][col] = val;
            val++;
        }
    }

    n = 3, m = 4;

    WavePrint(a,n,m);
    cout << endl;
    return 0;
}
