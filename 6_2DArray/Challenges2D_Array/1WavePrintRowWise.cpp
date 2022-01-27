//WAP wave print of 2D array row wise

#include <iostream>
using namespace std;

void WavePrintRowWise(int a[][10], int m, int n){
    int sr = 0, sc = 0, er = m-1, ec = n-1;
    while(sr<=er){
        if(sr%2==0){
            int col;
            for(col = sc; col<=ec; col++){
                cout << a[sr][col] << ", ";
            }
          
        sr++;
        }

        else{
            int col;
            for(col = ec; col>=sc; col--){
                cout << a[sr][col] << ", ";
            }
        sr++;
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

    WavePrintRowWise(a,m,n);
    
    cout << endl;
    return 0;
}
