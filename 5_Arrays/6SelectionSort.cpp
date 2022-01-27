//Selection Sort
//make number in increasing order

#include <iostream>
using namespace std;

int main(){
    int a[100];
    int n,i,min;
    cout << "Enter the Value of n: ";
    cin >> n;
    for(i = 0; i<n; i++){
        cin >> a[i];
    }

    for(i = 0; i<n; i++){
        cout << a[i]<<" ";
    }
    cout << endl;

    int count = 0;
    for(i = 0; i<n-1; i++){
        min = i;

        for(int j = i+1; j<n; j++){
            if(a[j]<a[min]){
            min = j;
            count++;
            }
        }
        swap(a[i],a[min]);
    }
    

    for(i = 0; i<n; i++){
        cout << a[i]<<" ";
    }
    cout << endl;
    cout << count/2;
    cout << endl;
    return 0;
}