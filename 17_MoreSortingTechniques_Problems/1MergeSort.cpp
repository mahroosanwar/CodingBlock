//Merge sort

#include <iostream>
using namespace std;

//merge the two sorted array
void merge(int *a, int s, int e){
    int mid = (s+e)/2;

    int i = s, j = mid+1, k = s;
    int temp[100] = {0};

    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }

    //for remaining values
    while(i<=mid){
        temp[k++] = a[i++];
    }

    while(j<=e){
        temp[k++] = a[j++];
    }

    for(int i = s; i<=e; i++){
        a[i] = temp[i];
    }
    
}

void mergesort(int *a, int s, int e){
    //base case
    if(s>=e){
        return;
    }

    //recursive case
    int mid = (s+e)/2;

    mergesort(a, s, mid);
    mergesort(a, mid+1, e);

    //merge the sorted array

    merge(a, s, e);

}

int main(){
    int n;
    cin>> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    mergesort(a, 0, n-1);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
