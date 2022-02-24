//FirstOccurance

#include <iostream>
using namespace std;


//by updating array address and decreasing the no of elements 
int FirstOccurance(int *a, int n, int key){
    //Base Case
    if(n==0){
        return -1;
    }
    
    //Recursive Case
    if(a[0]==key){
        return 0;
    }
    int i = FirstOccurance(a+1, n-1, key);
    if(i==-1){
        return -1;
    }
    return i+1;
}


//by updating the iterator
int FirstOccurance_i(int *a, int n, int i, int key){
    //base case
    if(i==n){
        return -1;
    }
    if(a[i] == key){
        return i;
    }

    return FirstOccurance_i(a, n, i+1, key);
}
int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i< n; i++){
        cin >> a[i];
    }

    int key;
    cin >> key;

    cout << FirstOccurance(a,n,key);

    cout << '\n' << FirstOccurance_i(a,n,0,key);

    return 0;
}
