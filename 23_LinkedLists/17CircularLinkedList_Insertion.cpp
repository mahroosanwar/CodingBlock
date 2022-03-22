// Circular Linked List - Insertion

#include <iostream>
using namespace std;

//linked list is collection of nodes that store some data
//structure of node (need to rap your data and pointer into the same bucket)
class node{
public:
    int data;
    node*next;

    // constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

void insert(node*& head, int data){

    node* n = new node(data);
    node* temp = head;

    n->next = head;

    if(temp != NULL){
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = n;
    }
    else{
        n->next = n;
    }
    head  = n;
}

void print(node*head){
    node*temp = head;
    while(temp->next != head){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
    return;
}

int main(){

    node*head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    print(head);

    return 0;
}
