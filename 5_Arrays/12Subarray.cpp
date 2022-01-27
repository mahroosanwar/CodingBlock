// Subarry is Continuous set of number present in an array

#include <iostream>
#include <algorithm>
using namespace std;

void All_SubArray(int a[],int n){
    
    for(int i = 0; i<n; i++){
        
        for(int j = i; j<n; j++){
            
            for(int k = i; k<=j; k++){
                
                cout << a[k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(){
    int a[] = {2,3,1, 4,5};
    int n = sizeof(a) / sizeof(int);
    All_SubArray(a,n);

    cout << endl;
    return 0;
}