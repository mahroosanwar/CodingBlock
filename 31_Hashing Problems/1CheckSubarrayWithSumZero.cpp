//Hashing 01 - Check Subarray With Sum Zero
//Array contains a subarray whose sum is zero or not

#include<iostream>
#include<unordered_set>         
using namespace std;

bool checkSum(int arr[], int n) {
     
    unordered_set<int> s;

    int pre=0;  //prefix sum
    for(int i=0; i<n; i++) {
        pre += arr[i];
        //check if sum was already present in the set
        //-->s.find() function return the iterator end of the set if
        //the number you are finding is not present otherwise it will return location of that
        if(pre==0 or s.find(pre) != s.end()) {
            return true;
        }
        s.insert(pre);
    }

    return false;
} 

int main() {

    int n;
    cin>>n;
    
    int arr[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i]; 
    }

    if(checkSum(arr, n)) {
        cout << "True"; 
    }
    else {
        cout << "False";
    }

    return 0;
}

