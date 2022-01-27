// target Sum Pairs

#include <iostream>
#include <algorithm>
using namespace std;

void SumPairs(int a[], int n, int target){
    int i = 0, j = n-1;

    while(i<j){
        if(a[i] + a[j] == target){
            cout << a[i] << " and " << a[j] << endl;
            i++;
            j--;
        }
        if((a[i] + a[j]) > target)
            j--;

        if((a[i] + a[j]) < target)
            i++;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);

    int target;
    cin >> target;

    SumPairs(a,n,target); 
    cout << endl;
    return 0;
}