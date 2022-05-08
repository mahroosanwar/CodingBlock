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