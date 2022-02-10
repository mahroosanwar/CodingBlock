//Some Other Useful STL

#include<iostream>
#include<algorithm>
using namespace std;

void PrintArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a)/sizeof(int);

    PrintArray(a,n);
    rotate(a,a+3,a+n);
    PrintArray(a,n);


    int x=10, y=20, z=30;
    cout << x << " " << y << endl;
    swap(x,y);
    cout << x << " " << y << endl;

    cout << endl;

    cout << "min of 2 num: " << min(x,y) << endl;
    cout <<"min of 3 num: " << min(x,min(y,z)) << endl;
    
    cout << endl;
    cout << "max of 2 num: " << max(x,y) << endl;
    cout <<"max of 3 num: " << max(x,max(y,z)) << endl;

    return 0;
}