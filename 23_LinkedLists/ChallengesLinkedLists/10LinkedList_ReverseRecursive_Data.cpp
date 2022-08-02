//Linked List - Reverse a Linked List (Recursive, Data)

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    //constructor
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

    node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new node(data);
    return;
}

void print(node*head){

    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* recReverse(node*head){

    //base case
    if(head == NULL || head->next == NULL) {
        return head;
    }

    //rec case

    node* smallHead = recReverse(head->next);

    // node* temp = head->next;        //by making this; optimize
    // temp->next = head;
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

int main(){
    node* head = NULL;
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int data;
        cin >> data;

        insertAtTail(head, data);
    }

    node* smallHead = recReverse(head);
    print(smallHead);

    return 0;
}


// Reverse a linked list by changing the data of its nodes in a recursive manner

// Input Format
// N -> number of nodes N spaces separated numbers -> content of linked list

// Constraints
// None

// Output Format
// N space separated numbers -> content of reversed linked list

// Sample Input
// 5
// 10 20 30 40 50
// Sample Output
// 50 40 30 20 10
