//Delete Nodes

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    //constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtTail(node* &head, int data){

    if(head == NULL){
        head = new node(data);
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new node(data);
}

void print(node* head){

    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void builtList(node* &head){
    int n;
    cin >> n;

    while(n--){
        int data;
        cin >> data;

        insertAtTail(head, data);
    }
}

node* DeleteNodes(node* &head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //rec case

    node* smallHead = DeleteNodes(head->next);
    
    node* temp = head->next;
    if(head->data < temp->data){
        head  = temp;
    }
    return  head;
}

int main(){
    node* head = NULL;
    builtList(head);

    head = DeleteNodes(head);

    print(head);

    return 0;
}

// Given a singly linked list delete all nodes which are having a greater value among any of the nodes residing on the right side.

// Input Format
// First line contains N, the number of nodes in the linked list.
// Next line contains the N nodes data .

// Constraints
// 0<N<10^9

// Output Format
// Print the linked list after deleting the nodes which are having a greater value on right side.

// Sample Input
// 8
// 12 15 10 11 5 6 2 3
// Sample Output
// 15 11 6 3 
// Explanation
// In the given case 12 is having right node greater than itself i.e. 12<15 so delete it.
// Similarly, 10<11, 5<6 and 2<3 so delete 10, 5 and 2 as well.
// Thus, linked list becomes 15->11->6->3.