// All Indices Problem

#include <iostream>
using namespace std;

void AllIndices(int *a, int n, int i, int M){
    //base case
    if(i == n){
        return;
    }

    //recursive case
    if(a[i] == M){
        cout << i << " ";
    }
    AllIndices(a, n, i+1, M);
}
int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int M;
    cin >> M;

    AllIndices(a, n, 0, M);
    
    return 0;
}