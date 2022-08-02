//Merge Sorted Linked Lists

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    //construct
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtTail(node*&head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }

    node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void print(node*head){
    
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* merge(node*a, node*b){
    //base case
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }

    //rec case
    //take a head pointer
    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }

    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main(){
    int T; cin >> T;

    for(int i=0; i<T; i++){
        
        node*head1 = NULL;
        node*head2 = NULL;
        
        int n1; cin >> n1;
        
        for(int i=0; i<n1; i++){
            int data; cin >> data;
            insertAtTail(head1, data);
        }

        int n2; cin >> n2;

        for(int i=0; i<n2; i++){
            int data; cin >> data;
            insertAtTail(head2, data);
        }

        node* newHead = merge(head1, head2);

        print(newHead);
    }    
    return 0;
}


// Given 2 sorted linked lists , merge the two given sorted linked list and print the final Linked List.

// Input Format
// First Line contains T the number of test cases.
// For each test case :
// Line 1 : N1 the size of list 1
// Line 2 : N1 elements for list 1
// Line 3 : N2 the size of list 2
// Line 4 : N2 elements for list 2

// Constraints
// 1 <= T <= 1000
// 0<= N1, N2 <= 10^6
// -10^7 <= Ai <= 10^7

// Output Format
// For each testcase , print the node data of merged linked list.

// Sample Input
// 1
// 4
// 1 3 5 7
// 3
// 2 4 6
// Sample Output
// 1 2 3 4 5 6 7 
// Explanation
// The two lists after merging give the sorted output as [1,2,3,4,5,6,7] .
