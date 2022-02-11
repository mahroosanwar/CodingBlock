//Array Binary Search

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int n;
    cin >> n;

    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;

    //key(m) address - a address gives the index value of key
    int index = find(a, a+n, m) - a;

    if(index==n){
        cout << -1;
    }
    else{
        cout << index;
    }

    return 0;
}
