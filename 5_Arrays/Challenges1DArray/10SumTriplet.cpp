// Find the Sum triplet for a target

#include <iostream>
#include <algorithm>
using namespace std;

void SumTriplet(int a[], int n, int target){
    
    for(int i = 0; i<n-2; i++){
        int j = i+1 , k = n-1;

        while(j<k){
            if(a[i] + a[j] + a[k] == target){
                cout << a[i] << ", " << a[j] << " and " << a[k] << endl;
                j++;
                k--;
            }
            if(a[i] + a[j] + a[k] > target){
                k--;
            }
            if(a[i] + a[j] + a[k] < target){
                j++;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);

    int target;
    cin >> target;

    SumTriplet(a,n,target);
    
    cout << endl;
    return 0;
}