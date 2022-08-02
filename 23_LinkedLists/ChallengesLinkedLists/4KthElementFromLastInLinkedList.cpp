// Kth element from last in linked list

#include <iostream>
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

    node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = new node(data); 
    return;
}

node* takeInput(){

    int d;
    cin >> d;

    node* head = NULL;
    while(d != -1){
        insertAtTail(head, d);
        cin >> d;
    }

    return head;
}

node* kthElement(node*head, int k){
    
    if(head == NULL || head->next == NULL){
        return head;
    }

    node*fast = head;
    node*slow = head;

    int cnt = 1;
    while(fast != NULL){
        if(cnt <= k){
            fast = fast->next;
            cnt++;
        }
        else{
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    return slow;
}

void print(node*head){

    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    node* head = takeInput();

    int k;
    cin >> k;

    node* kth = kthElement(head, k);
    cout << kth->data;

    return 0;
}

// Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.

// Input Format
// First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.

// Constraints
// n < 10^5

// Output Format
// Output a single line containing the node value at the kth element from last.

// Sample Input
// 1 2 3 4 5 6 -1
// 3
// Sample Output
// 4
// Explanation
// The linked list is 1 2 3 4 5 6. -1 is not included in the list. So the third element from the last is 4
