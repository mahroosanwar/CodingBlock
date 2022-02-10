#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[] = {5, 6, 4, 10, 8};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin >> key;

    int *ans = find(arr, arr+n, key); 
    int indx = ans-arr;

    if(indx == n){
        cout << "key not found" << endl;
    }
    else{
        cout << "Key found at : " << indx << endl; 
    }
    
    return 0;
}
