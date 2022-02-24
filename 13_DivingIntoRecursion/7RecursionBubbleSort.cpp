// Recursion bubble sort

#include <iostream>
using namespace std;

void RecursionBubbleSort(int *a, int n, int i){
    // base case
    if(i == n-1){
        return;
    }
    //Recursive case

    for(int j=0; j < n-1-i; j++){
        if(a[j] > a[j+1]){
            swap(a[j], a[j+1]);
        }
    }
    RecursionBubbleSort(a,n,i+1);
}

void print(int *a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    RecursionBubbleSort(a, n, 0);
    print(a,n);
    return 0;
}