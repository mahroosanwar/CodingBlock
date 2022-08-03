//Find kth Largest Number

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthLargestNumber(vector<int> arr, int k) {
     
    priority_queue<int, vector<int>, greater<int> > pq;         //min priority queue

    //push kth element in pq
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }

    //push remaining element one by one only if
    //it is greator than top of pq
    for(int i=k; i<arr.size(); i++) {
        if(pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for(int i=0; i<n; i++) {
        int no;
        cin >> no;
        v.push_back(no);
    }

    cout << kthLargestNumber(v, k);

    return 0;
}


// Find the kth largest element in an unsorted array.
// Note:It is the kth largest element in the sorted order, not the kth distinct element.

// Input Format
// First line contains integer n as size of array. Second line contains the value of k. Third line contains n integers as element of array.

// Constraints
// 1 ≤ k ≤ array's length.

// Output Format
// Print the kth largest element as output.

// Sample Input
// 6
// 2
// 3 2 1 5 6 4
// Sample Output
// 5
