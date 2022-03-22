//Is array Soted method 2

#include <iostream>
using namespace std;

bool isSorted(int *a, int n, int i){
    //Base case
    if(i == n-1){
        return true;
    }

    //Recursive Case

    bool isSmallerSorted = isSorted(a,n,i+1);
    if(isSmallerSorted && a[i]< a[i+1]){
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

    bool ans = isSorted(a,n,0);

    if(ans){
        cout << "true" ;
    }
    else{
        cout << "false" ;
    }
    return 0;
}