//Merge Sort Using Recursion

#include <iostream>
using namespace std;

void Merge(int *a, int *b, int *c, int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;

    //travers both array

    while(i<=mid && j<=e){
        if(b[i] <= c[j]){
            a[k++] = b[i++];
        }
        else{
            a[k++] = c[j++];
        }
    }

    //for remaining values

    while(i <= mid){
        a[k++] = b[i++];
    }
    
    while(j <= e){
        a[k++] = c[j++];
    }
}

void MergeSortRec(int *a, int s, int e){
    //base case
    if(s >= e){
        return;
    }

    //recursion case
    int mid = (s+e)/2;
    int b[100], c[100];
    
    //divide array into two parts
    for(int i=0; i<=mid; i++){
        b[i] = a[i];
    }
    
    for(int i=mid+1; i<=e; i++){
        c[i] = a[i];
    }
    
    MergeSortRec(b, s, mid);
    MergeSortRec(c, mid+1, e);

    //Merge Sort

    Merge(a, b, c, s, e);
}

int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    MergeSortRec(a,0,n-1);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}


// Implement Merge Sort in a linked list using recursion

// Input Format
// Enter the size of the linked list N and take N more inputs

// Constraints
// The number of nodes in the list is in the range [0, 5 * 10^4]. -10^5 <= Node.val <= 10^5

// Output Format
// Display the elements of the sorted list in a space separated manner

// Sample Input
// 4
// 9
// 6
// 3
// 2
// Sample Output
// 2 3 6 9
// Explanation
// Now the list is sorted.
