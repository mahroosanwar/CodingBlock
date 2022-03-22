// Is Array Sorted?

#include <iostream>
using namespace std;

bool isSorted(int *a, int n){
    //base case
    if(n==0 || n==1){
        return true;
    }

    //Recursive case 
    bool isSmallerSorted = isSorted(a+1, n-1);

    if(isSmallerSorted && a[0] <= a[1]){
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

    bool ans = isSorted(a,n);
    if(ans){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}