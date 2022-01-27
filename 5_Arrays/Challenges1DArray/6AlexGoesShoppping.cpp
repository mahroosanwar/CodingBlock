//Alex Goes Shopping

#include <iostream>
using namespace std;

void Shopping(int arr[], int n ,int A, int k){

    int count  = 0;
    for(int i = 0; i<n; i++){

        if((A % arr[i]) == 0){
            count++;
        }
    }
    if(count >= k){             //Count can be greater than equal to k
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int q,A,k;              //Queries
    cin >> q;

    for(int i = 0; i<q; i++){
        cin >> A;               // A is total unit
        cin >> k;
        Shopping(arr,n,A,k);                        // k is no of items can buy
    }

    cout << endl;
    return 0;
}