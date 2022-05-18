//Longest Consecutive Subsequence-II (Unordered Map) 🆕

#include<iostream>
#include<unordered_map>
using namespace std;

int findLargestSeq(int arr[], int n) {

    unordered_map<int , int> m;     //number, streak_length

    for(int i=0; i<n; i++) {
        int no = arr[i];

         //if both of these no are not present (consecutive left & right) 
        if(m.count(no-1) == 0 and m.count(no+1) == 0) {
            //we starting new string whose length is 1
            m[no] = 1;
        }
        else if(m.count(no-1) and m.count(no+1)) {
            int len1 = m[no-1];     //left streak lenght
            int len2 = m[no+1];     //right streak lenght

            int streak = len1 + 1 + len2;       //total streak length
            //update starting and ending length 
            m[no-len1] = streak;
            m[no+len2] = streak;
        }
        else if(m.count(no-1) and !m.count(no+1)) {
            int len = m[no-1];      //1 2 3    7 8 9.  [4]
            m[no-len] = len+1;
            m[no] = len + 1;
        }
        else{
            int len = m[no+1];      //5 6 7  9(updated streak_len: 4) 10 11 12(4).  [9]
            m[no+len] = len+1;
            m[no] = len + 1;
        }

    }

    int largest = 0;
    for(auto p : m) {
        largest = max(largest, p.second);
    }

    return largest;
}

int main() {
    
    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
    int n = sizeof(arr)/sizeof(int);

    cout << findLargestSeq(arr, n);

    return 0;
}