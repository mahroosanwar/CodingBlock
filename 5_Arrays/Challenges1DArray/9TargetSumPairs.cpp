//Array Target Sum Pairs

#include <iostream>
using namespace std;

int InsertionSort(int a[], int n){
  
  int j;
  for(int i=0; i<n-1; i++){
    int PickedUp = a[i];
    for(j=i-1; j>=0 && PickedUp < a[j]; j--){
      a[j+1] = a[j];
    }
    a[j+1] = PickedUp;
  }
  return *a;5
}

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  
  *a = InsertionSort(a,n);
  for(int i = 0; i<n; i++){
    cout << a[i] << " ";
  }

  cout << endl;
  return 0;
}

// Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

// Input Format
// The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

// Constraints
// Length of the arrays should be between 1 and 1000.

// Output Format
// Print all the pairs of numbers which sum to target. Print each pair in increasing order.

// Sample Input
// 5
// 1
// 3
// 4
// 2
// 5
// 5
// Sample Output
// 1 and 4
// 2 and 3
// Explanation
// Find any pair of elements in the array which has sum equal to target element and print them.
