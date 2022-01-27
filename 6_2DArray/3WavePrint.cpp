#include <iostream>
using namespace std;

int main(){

    int n = 4, m = 5;
    int a[n][m];
    int val = 1;
    for(int row=0; row<n; row++){
        for(int col = 0; col<m; col++){
            a[row][col] = val;
            val++;
        }
    }

    for(int row=0; row<n; row++){
        for(int col = 0; col<m; col++){
            cout << a[row][col]<< " ";
        }
        cout << endl;
    }

    n = 3, m = 4;
    for(int col = 0; col<m; col++){
        if(col%2 == 0){
            for(int row=0; row<n; row++){
                cout << a[row][col] << " ";
            }
            cout << endl;
        }
        else{
            for(int row=n-1; row>=0; row--){
                cout << a[row][col] << " ";
            }
        cout << endl;
        }
    }
    cout <<endl;
    return 0;
}