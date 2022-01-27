// Find The pair of Roses the Deepak can buy

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void PairofRose(int a[], int n, int money){
    int i=0, j = n-1, diff, first, second, min = INT_MAX;
    while(i<j){
        if(a[i]+a[j] == money){
            diff = abs(a[j] - a[i]);    //it gives the Difference of two numbers
            if(diff <= min){            //make difference minimum
                min  = diff;
                first = a[i];           
                second  = a[j];
            }
            i++;
            j--;
        }
        
        if(a[i]+a[j]>money){
            j--;
        }

        if(a[i]+a[j]<money){
            i++;
        }
    }
    cout << "Deepak should buy roses whose prices are " << first << " and " << second << "." << endl;
}
int main(){
    int t;
    cin >> t;
    int n;
    for(int i = 0; i<t; i++){
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a,a+n);

        int money;          //Money
        cin >> money;

        PairofRose(a,n,money);

    }
    cout << endl;
    return 0;
}