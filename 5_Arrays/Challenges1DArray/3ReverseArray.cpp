// Reversing the array

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void ReverseArray(int a[], int n){
    for(int i =0; i<n/2; i++){
        swap(a[i],a[n-1-i]);
    }
    for(int i=0; i<n; i++){
        cout << a[i]<< endl;
    }
}

int main(){
    
    int a[1000];
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    ReverseArray(a,n);
    cout << endl;
    return 0;
}