// Sorting 
// make number in  increasing number

#include <iostream>
using namespace std;

int main(){
    int a[100];
    int i,n;
    cout << "Enter the value of n(max : 100): "<< endl;
    cin >>n;

    for (i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int j = 0; j<n-1; j++){         //and repeat below process n-1 times

        for(i=0; i<n-1; i++){           //Process goes till n-2 index because no index 
            if(a[i]>a[i+1]){            //after n-1 index 
                swap(a[i],a[i+1]);
            }
        }
    }

    for(i = 0; i<n; i++){
        cout << a[i]<<" ";
    }
    cout << endl;
    return 0;
}
