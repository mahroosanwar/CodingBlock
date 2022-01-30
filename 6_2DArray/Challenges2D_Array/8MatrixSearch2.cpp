//matrix Search StairCase method

#include <iostream>
using namespace std;

void MatrixSearch(int a[][100], int n, int m, int key){
    int i = 0, j = m-1;

    bool isNumPresent = false;
    while(i<n && j>=0){
        if(a[i][j] < key)
            i++;
        else if(a[i][j] > key)
            j--;
        if(a[i][j] == key){
            isNumPresent = true;
            cout << isNumPresent;
            break;
        }
    }
    if(isNumPresent == false)
        cout << isNumPresent;
}

int main(){
    int a[100][100];
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    int key;
    cin >> key;
    
    MatrixSearch(a,n,m,key);
    
    cout << endl;
    return 0;
}