//inbuilt sort ; make number in decreasing number

#include <iostream>
#include <algorithm>


using namespace std;

compare(int a, int b){
    return a>b;
}

int main(){
    int a[] = {1, 2, 4, 6, 6, 7, 8, 3, 5};
    int n = sizeof(a) / sizeof(int);

    for(int i=0; i<n; i++){
        cout << a[i]<<" ";
    }
    cout << endl;

    sort(a,a+n,compare);

    for(int i=0; i<n; i++){
        cout << a[i]<<" ";
    }

    cout << endl;
    return 0;
}