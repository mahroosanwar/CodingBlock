//Generic Programming with Templates

#include <iostream>
#include <cstring>
using namespace std;

//freedom from -- data types
template<typename T>
int search(T arr[], int n, T key){

    //linear search
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return n;
}

int main(){
    int arr[] = {10, 12, 23, 4, 9};
    int n = sizeof(arr)/sizeof(int);

    // cout << search(arr, n, 23);

    float b[] = {1.1, 1.2, 1.3};
    float k = 1.3;
    cout << search(b, 3, k);
    return 0;
}
