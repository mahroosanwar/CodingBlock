//Merge K sorted Arrays

#include<iostream>
#include<vector>
#include<queue>
using  namespace std;

typedef pair<int, pair<int, int> > node;

vector<int> mergeKsortedArrays(vector<vector<int> > arr) {

    vector<int> result;

    priority_queue<node, vector<node>, greater<node> > pq;      //min priority queue

    //insert 0th element of every row in pq
    for(int i=0; i<arr.size(); i++) {
        pq.push({arr[i][0], {i, 0}});
    }

    //remove the element one by one from the min heap and add to the result
    while(!pq.empty()) {
        node current = pq.top();
        pq.pop();

        int element = current.first;
        int row = current.second.first;
        int col = current.second.second;

        result.push_back(element);

        //push next element in pq next of the current element row, col+1(may be col dosen't exist)
        //push only if col exist
        if(col+1 < arr[row].size()) {
            pq.push({arr[row][col+1], {row, col+1}});   
        }
    }
    return result;
}

int main() {

    int k, n;
    cin >> k  >> n;

    vector<vector<int> > arr;
    for(int i=0; i<k; i++) {
        vector<int> v;
        for(int i=0; i<n; i++) {
            int no;
            cin >> no;
            v.push_back(no);
        }
        arr.push_back(v);
    }

    vector<int> output = mergeKsortedArrays(arr);

    for(auto x : output) {
        cout << x << " ";
    }

    return 0;
}
