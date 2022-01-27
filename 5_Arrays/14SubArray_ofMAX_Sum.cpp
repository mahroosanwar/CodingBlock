// SubArray of Max Sum

// Print Max. Sum of Sub Array

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void SubArrayof_Max_Sum(int a[], int n){
    int wi,wj,max_sum = INT_MIN;
    for (int i = 0; i<n; i++){
        
        for(int j = i; j<n; j++){
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum += a[k];
            }
            if(sum > max_sum){
                max_sum = sum;
                wi = i;     //i,j when sum is max
                wj = j;
            }
        }
    }
    cout << "SubArray of Max Sum: "; 
    for(int i = wi; i<=wj; i++){
        cout << a[i]<< " ";
    }
    cout << endl;
    cout << "Max Sum of SubArray: " << max_sum;
}

int main(){
    int a[] = {1,4,-2,3,9,-6,2};
    int n = sizeof(a) / sizeof(int);

    SubArrayof_Max_Sum(a,n);

    cout << endl;
    return 0;
}
