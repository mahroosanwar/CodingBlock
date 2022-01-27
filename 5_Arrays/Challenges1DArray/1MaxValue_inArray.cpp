// Max value In Array

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void MaxValue(int a[], int n){
    int max = INT_MIN;
    
    for(int i = 0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout << a[n-1];
}
int main(){
    int a[1000];
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    MaxValue(a,n);
    cout << endl;
    return 0;
}
