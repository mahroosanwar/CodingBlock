//WAP to Digonal traversal\

#include <iostream>
using namespace std;

void DigonalTraversal(int a[][100], int m, int n){
    int i=0, j=0;

    bool isUP = true; 

    for(int k = 0; k<m*n;){

        if(isUP){
            for( ; i>=0 && j<n; i--, j++){
                cout << a[i][j] << " ";
                k++;
            }
            if(i<0 && j<n){
                i = 0;
            }

            if(j==n){
                i = i+2;
                j--;
            }
        }

        else{
            for( ; j>=0 && i<m; j--, i++){
                cout << a[i][j] << " ";
                k++;
            }

            if(j<0 && i<m){
                j = 0;
            }

            if(i==m){
                j = j+2;
                i--;
            }
        }

        isUP = !isUP; 
    }
}

int main(){
    int a[100][100];
    int m,n;
    cin >> m >> n;

    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            cin >> a[row][col];
        }
    }

    DigonalTraversal(a,m,n);

    cout << endl;
    return 0;
}