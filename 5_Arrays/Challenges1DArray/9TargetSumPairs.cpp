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
