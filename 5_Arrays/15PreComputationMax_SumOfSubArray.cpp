// Max Sum of SubArray using Pre Cumputation(Cumulative Sum)

#include <iostream>
#include <cmath>

using namespace std;

void Max_sumSubArray(int a[], int n){
    int wi, wj, max_sum = INT_MIN;
    int csum[1000] = {0};        

    for(int i = 1; i<n; i++){
        csum[i] += csum[i-1] + a[i];
    }
    
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int sum = 0;
            sum += csum[j] - csum[i-1];
            if(max_sum < sum){
                max_sum = sum;
                wi = i;
                wj = j;
            }
        }
    }
    cout << "SubArray of Max Sum: ";
    for(int i = wi; i<=wj; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Max Sum of SubArray: " << max_sum << endl;
}

int main(){
    int a[] = {0,1,4,-2,3,9,-6,2};
    int n = sizeof(a) / sizeof(int);
    
    Max_sumSubArray(a,n);

    cout << endl;
    return 0;
}