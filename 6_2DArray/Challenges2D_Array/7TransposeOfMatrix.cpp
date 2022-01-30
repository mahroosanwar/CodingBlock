//WAP to find the transpose of matrix

#include <iostream>
using namespace std;

void Transpose(int a[][100], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
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

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            cin >> a[row][col];
        }
    }

    Transpose(a,n);

    cout << endl;
    return 0;
}