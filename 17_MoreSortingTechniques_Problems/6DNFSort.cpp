//DNF Sort

#include <iostream>
using namespace std;

void DNFSort(int *a, int n){
    
    //sort arrays 0's, 1's, 2's
    int lo = 0;
    int hi = n-1;
    int mid = 0;

    while(mid<=hi){
        if(a[mid] == 0){
            swap(a[lo], a[mid]);
            lo++;
            mid++;
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{
            swap(a[mid], a[hi]);
            hi--;
        }
    }
}

int main(){
    int a[] = {2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 2, 0};
    int n = sizeof(a)/sizeof(int);

    DNFSort(a, n);

    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}