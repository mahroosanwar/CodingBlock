//isArraySorted-1

#include <iostream>
using namespace std;

bool isArraySorted_1(int *a, int n){
    //Base case
    if(n==0 || n==1){
        return true;
    }
    //recursive case
    bool isSmallerSorted = isArraySorted_1(a+1, n-1);
    
    if(isSmallerSorted && a[0]<=a[1]){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    int n;
    cin >> n;

    int a[n];    
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    bool ans = isArraySorted_1(a, n);
    if(ans){
        cout << "Sorted";
    }
    else{
        cout << "Not Sorted";
    }
    
    return 0;
}