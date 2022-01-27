//Find The Pair

#include <iostream>
#include <algorithm>
using namespace std;

void SumPair(int a[], int n, int target){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((a[i]+a[j])==target){
                cout << a[i] << " and " << a[j] << endl;
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

    SumPair(a,n,target);

    cout << endl;
    return 0;
}