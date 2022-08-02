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

// You are provided two sorted arrays. You need to find the maximum length of bitonic subsequence. You need to find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays. You can switch from one array to another array only at common elements.

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains two integers n and m which is the size of arrays and next two lines contains n and m space separated integers respectively.

// Constraints
// 1<=t<=100 1<=n,m<=100000

// Output Format
// Print the maximum path.

// Sample Input
// 1
// 8 8
// 2 3 7 10 12 15 30 34
// 1 5 7 8 10 15 16 19
// Sample Output
// 122
// Explanation
// 122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34
