//First Index

#include <iostream>
using namespace std;

int FirstIndex(int *a, int n, int i, int M){
     //Base Case
    if(i == n){
        return -1;
    }
    //Recursive Case
    if(a[i] == M){
        return i;
    }
    int index = FirstIndex(a, n, i+1, M);

    return index;
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

    int ans = FirstIndex(a, n, 0, M);
    cout << ans;
    return 0;
}
