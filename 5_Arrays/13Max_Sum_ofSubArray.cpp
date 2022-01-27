// Print Max. Sum of Sub Array

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void All_SubArray(int a[], int n){
    
    for (int i = 0; i<n; i++){
        
        for(int j = i; j<n; j++){
            
            for(int k = i; k<=j; k++){
                cout << a[k]<< " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Max_Sum_ofSubArray(int a[], int n){
    int max_sum = INT_MIN;
    for (int i = 0; i<n; i++){
        
        for(int j = i; j<n; j++){
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum += a[k];
            }
            if(sum>max_sum){
                max_sum = sum;
            }
        }
    }
    cout << "Max Sum of SubArray: " << max_sum;
}

int main(){
    int a[] = {1,4,-2,3,9,-6,2};
    int n = sizeof(a) / sizeof(int);

    All_SubArray(a,n);
    cout << endl;

    Max_Sum_ofSubArray(a,n);

    cout << endl;
    return 0;
}