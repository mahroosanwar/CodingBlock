//Merge Sort

#include <iostream>
using namespace std;


//merge two sorted array
void merge(int *a, int *b, int *c, int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;

    // Traverse both array

    while(i<=mid && j<=e){

        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array

        if(b[i] < c[j]){
            a[k++] = b[i++];
        }
        else{
            a[k++] = c[j++];
        }
    }
    // Store remaining elements of array

    while(i <= mid){
        a[k++] = b[i++];
    }
    while(j <= e){
        a[k++] = c[j++];
    }
    
}

void mergeSort(int *a, int s, int e){
    //base case
    if(s>=e){
        return;
    }

    //Divide the array

    int mid = (s+e)/2;
    int b[100], c[100];

    for(int i=s; i<=mid; i++){
        b[i] = a[i];
    }
    for(int i=mid+1; i<=e; i++){
        c[i] = a[i];
    }

    //sort (Recursive Case)
    mergeSort(b, s, mid);
    mergeSort(c, mid+1, e);

    //merge
    merge(a,b,c,s,e);
}

void printArray(int *a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int a[] = {4,5,2,10,12,11};
    int n = sizeof(a)/sizeof(int);

    cout << "Before sorting: " << endl;
    printArray(a,n);
    mergeSort(a, 0, n-1);
    cout << '\n' << "After Sorting: " << endl;
    printArray(a,n);

}