//Search number x in matrix present or not

#include <iostream>
using namespace std;
void MatrixSearch(int a[][100], int n, int m, int Key){
    bool isNumFound = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == Key){
                isNumFound = true;
                cout << isNumFound;
            }
        }
    }
    if(isNumFound == false){
        cout << isNumFound;
    }
}
int main(){
    int a[100][100];
    int n,m;
    cin >> n >> m;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            cin >> a[row][col];
        }
    }
    int x;
    cin >> x;

    MatrixSearch(a,n,m,x);

    cout << endl;
    return 0;
}