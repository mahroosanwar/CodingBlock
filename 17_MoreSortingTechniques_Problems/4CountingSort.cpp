//Counting Sort

#include <iostream>
using namespace std;

void CountingSort(int *a, int n){
    //largest in the array assuming no's are > 0
    int largest = -1;
    
    for(int i=0; i<n; i++){
        largest = max(largest, a[i]);
    }

    //creat a freq array
    
    int *freq = new int[largest + 1]{0};

    for(int i=0; i<n; i++){
        freq[a[i]]++;
    }

    //put back the element in array a[] by reading frequency array
    int j = 0;
    for(int i=0; i<=largest; i++){
        while(freq[i] > 0){
            a[j] = i;
            freq[i]--;
            j++;
        }
    }

}

int main(){
    int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    int n = sizeof(arr)/sizeof(int);

    CountingSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}