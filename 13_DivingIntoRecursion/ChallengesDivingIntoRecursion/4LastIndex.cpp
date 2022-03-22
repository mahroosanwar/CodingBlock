//Last Index

#include <iostream>
using namespace std;

int LastIndex(int *a, int n, int i, int M){
    //Base Case
    if(i == n){
        return -1;
    }

    //Recursive Case
    if(a[i] == M){
        //could be found

        int bi = LastIndex(a, n, i+1, M);

        if(bi != -1){
            return bi;
        }
        
        else{
            return i;
        }
    }

    int index = LastIndex(a, n, i+1, M);
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

    int ans = LastIndex(a, n, 0, M); 

    cout << ans;
    return 0;
}