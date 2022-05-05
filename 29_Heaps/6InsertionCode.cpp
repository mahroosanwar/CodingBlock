//Insertion Code

#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b) {
        if(minHeap) {
            return a < b;
        }
        else {
            return a > b;
        }
    }
public:
    Heap(int default_size = 10, bool type = true) {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int d) {
        v.push_back(d);
        int idx = v.size() - 1;         //"-1" bcz first index is blocked (i.e. if elements are 10 so vector size will be 11) 
        int parent_idx = idx/2;

        //keep pushing to the top till you reach root node or stop midway bcz current
        //element is greater than parent
        while(idx > 1 && compare(v[idx], v[parent_idx]) ) {
            swap(v[idx], v[parent_idx]);
            idx = parent_idx;
            parent_idx = parent_idx/2;
        }
    }
};


int main() {

    // give some initial size and type
}
