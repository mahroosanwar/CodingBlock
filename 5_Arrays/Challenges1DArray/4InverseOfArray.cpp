// Inverse Of An Array

#include <iostream>
using namespace std;

void InverseArray(int a[], int n, int f[]){
    int j;
    for(int i=0; i<n; ++i){
            j = a[i];
            f[j] = i;  
    }
    
    for(j = 0; j<n; j++){
        cout << f[j] << " ";
    }
}

int main(){

    int n;
    cin >> n;
    
    int a[n],f[n];      //added f an array

    for(int i; i<n; i++){
        cin >> a[i];
    }

    InverseArray(a,n,f);
    

    cout << endl;
    return 0;
}