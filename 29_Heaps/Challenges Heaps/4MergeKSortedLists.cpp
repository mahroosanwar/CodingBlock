//Merge K Sorted Lists

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d) {
        data = d;
        next = NULL;
    }
};

void insertAtTail(node* &head, int data){
    //if there is no data 
    if(head == NULL){
        head = new node(data);
        return;
    }
    
    //otherwise need to find tail point
    node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void printList(node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Comparison object to be used to order the min-heap
class compare{
public:
    bool operator() (node *lhs, node *rhs) {
        return lhs->data > rhs->data;
    }
};

// The main function to merge given `k` sorted linked lists.
// It takes array `lists` of size `k` and generates the sorted output
node *mergeKSortedList(vector<node *> &lists) {

    //create a empty min heap
    priority_queue<node*, vector<node* >, compare> pq;

    // push the first node of each list into the min-heap
    for (node* list: lists) {
        pq.push(list);
    }

    // take two pointers, head and tail, where the head points to the first node
    // of the output list and tail points to its last node
    node *head = NULL;
    node *last = NULL;

    // run till min-heap is empty
    while (!pq.empty())
    {
        // extract the minimum node from the min-heap
        node* min = pq.top();
        pq.pop();
 
        // add the minimum node to the output list
        if (head == NULL) {
            head = last = min;
        }
        else {
            last->next = min;
            last = min;
        }
 
        // take the next node from the "same" list and insert it into the min-heap
        if (min->next != NULL) {
            pq.push(min->next);
        }
    }
    // return head node of the merged list
    return head;
}

int main() {

    int k;
    int n;

    cin >> k >> n;

    // an array to store the head nodes of the linked lists
    vector<node *> lists; 

    //input
    for(int i=0; i<k; i++) {
        node *head = NULL;
        for(int j=0; j<n; j++) {
            int data;
            cin >> data;
            insertAtTail(head, data);
        }
        lists.push_back(head);
    }

    node *ans = mergeKSortedList(lists);
    printList(ans);
    return 0;
}