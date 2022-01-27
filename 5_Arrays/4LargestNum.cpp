// Largest num

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a[100];
    int n, mx = INT_MIN;
    cout << "Enter the value of n:(max:100) ";
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        if(a[i]>mx){
            mx = a[i];
        }
    }
    cout << mx;
}