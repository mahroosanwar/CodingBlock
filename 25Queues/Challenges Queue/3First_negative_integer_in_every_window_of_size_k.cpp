// First negative integer in every window of size k

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> printFirstNegativeInteger(int arr[], int n, int k) {

    vector<int> ans;
    queue<int> q;

    for(int i=0; i<k-1; i++) {
        if(arr[i]<0) q.push(arr[i]);
    }

    for(int i=k-1; i<n; i++) {
        if(arr[i]<0) q.push(arr[i]);

        if(!q.empty()) {
            ans.push_back(q.front());

            if(q.front() == arr[i-k+1]) {
                q.pop();
            }
        }
        else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        for(auto x:printFirstNegativeInteger(arr, n, k)) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}


// You are given given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k. If a window does not contain a negative integer, then print 0 for that window.

// Input Format
// First line contains integer t as number of test cases. Each test case contains two lines. First line contains two integers n and k where n is length of the array and k is the size of window and second line contains n space separated integer.

// Constraints
// 1 < t < 10 1< n, k < 10000000

// Output Format
// For each test case you have to print the required output as given below.

// Sample Input
// 2
// 8 3
// 12 -1 -7 8 -15 30 16 28
//  8 4
// 12 -1 -7 8 -15 30 16 28
// Sample Output
// -1 -1 -7 -15 -15 0 
// -1 -1 -7 -15 -15
// Explanation
// For first test case : Subarray of window size 3 is ( 12 -1 -7), (-1, -7, 8), and so on.. Take first negative number from each window and print them.
