//Priority Queue STL

#include<iostream>
#include<queue>
using namespace std;

int main() {
    // priority_queue<int> pq;   (:: default maxHeap)
    priority_queue<int, vector<int>, greater<int> > pq;     //to make it minHeap
    int n;
    cin >> n;
    for(int i = 1; i<n; i++) {
        int no;
        cin >> no;
        pq.push(no);        //O(logN)
    }

    //remove the element from heap
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;

}