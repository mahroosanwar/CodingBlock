//isArraySorted-Iterator

#include <iostream>
using namespace std;

bool isArraySorted(int *a, int n, int i){
    if(i==n-1){
        return true;
    }

    bool isSmallerSorted = isArraySorted(a,n,i+1);
    if(isSmallerSorted && a[i]<a[i+1]){
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

    bool ans = isArraySorted(a,n,0);

    if(ans){
        cout << "Sorted";
    }
    else{
        cout << "Not Sorted";
    }
    return 0;
}