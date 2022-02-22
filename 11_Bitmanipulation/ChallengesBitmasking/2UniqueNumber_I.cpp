//Unique number 1 (all no present twice except one no.) find unique no

#include <iostream>
using namespace std;

void UniqueNum1(int a[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= a[i];
    }
    cout << ans << endl;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    UniqueNum1(a, n);

    return 0;
}