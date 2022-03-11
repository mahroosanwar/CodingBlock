//  Space Time Complexity Introduction
//  Comparison b/w bubble and merge sort(we use inbuilt sort function which also run in  nlogn complexity )

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void bubble_sort(int *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    } 
}

int main(){
    int n;
    cin >> n;
    int a[100000];

    // time_t start = clock(); 

    //create a reverse sorted array
    for(int i = 0; i<n; i++){
        a[i] = n-i;
    }

    time_t start = clock();
    bubble_sort(a, n);
    time_t end = clock();
    
    cout << "Bubble sort time: " << end  - start << endl;
    

    for(int i = 0; i<n; i++){
        a[i] = n - i;
    }
    //inbuilt sort ( insted of merge sort)
    start = clock();
    sort(a, a+n);
    end = clock();

    cout << "Merge Sort time: " << end - start << endl;    

    return 0;
}

