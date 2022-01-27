// Understanding Comparator function in depth

#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int a[], int n){
    for(int i = 0; i<n; i++){
        cout << a[i]<< " ";
    }
}
bool compare(int a, int b){
    return a > b;               //for increasing use order a<b
}

void BubbleSort(int a[],int n, bool(&mycompare)(int a, int n)){  //Using the help of function call
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-1-i; j++){
            if(mycompare(a[j],a[j+1])){                    //change a[j]and a[j+1] postion     
                swap(a[j],a[j+1]);                         //to change ascending and descending
            }
        }
    }
}

int main(){
    int a[] = {3,1,3, 4,0,5,2};
    int n = sizeof(a)/sizeof(int);

    cout << "Before Bubble Sort: ";
    printArray(a,n);
    cout << endl;
    //calling bubble sort
    // sort(a,a+n,compare);
    BubbleSort(a,n,compare);        //calling compare as a parameter ; same as sort function

    cout << "After Bubble sort: ";
    printArray(a,n);

    cout << endl;
    return 0;

}
