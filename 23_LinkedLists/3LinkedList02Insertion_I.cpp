//Linked List 02 - Insertion-I

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
//there are multiple ways to implement a linked list
//1--> by making Linked list class (object oriented programming)

// class Linkedlist{
//     node*head;
//     node*tail;

// public:
//     Linkedlist(){

//     }
//     void Insertion(int d){
//         ...   
//     }
//     ...
//     ...
// };

//2--> or Function (Procedural Programming) that perform diff. operation in linked list

//passing a pointer by reference (no copy of actual head will created)
void insertAtHead(node*&head, int d){
    //when head is null
    if(head == NULL){
        head = new node(d);
        return;
    }
    //when head is not null
    node *n = new node(d);
    n->next = head;
    head = n;
}

//here head value is not pass by reference so when it pass by reference  head actual value become NULL 
//after first print; so we do not want to change actual value of head to be null ;

void print(node*head){

    while(head!=NULL){
        cout << head->data << " ->";
        head = head->next;
    }
    cout << endl;
}

int main(){
    node*head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);


    print(head);
    print(head);
    return 0;

}
