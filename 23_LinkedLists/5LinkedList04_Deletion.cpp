//Linked List 04 - Deletion

//Linked List 03 - Insertion II

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

//length of linked list
int length(node*head){
    int cnt=0;
    while(head != NULL){
        cnt++;
    head = head->next;
    }
    return cnt;
}

void insertAtTail(node*&head, int data){
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

void insertInMiddle(node*head, int data, int p){       //p--> position
    //corner case
    if(head == NULL || p==0){
        insertAtHead(head, data);
    }

    else if(p>length(head)){
        insertAtTail(head, data);
    }


    //for insertion in middle
    else{
        //take p-1 jumps
        int jump = 1;
        node* temp = head;
        while(jump <= p-1){
            temp = temp->next;
            jump++;
        }

        //create a new node
        node* n = new node(data);
        n-> next = temp-> next;
        temp-> next  = n;
    }
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

//deteteHead does not delete head pointer , delete the node that is at the beginning of the linked list
void deleteHead(node*&head){
    //corner case
    if(head == NULL){
        return;
    }

    // first store address of next node
    node*temp = head->next;
    delete head;
    head = temp;
}

int main(){
    node*head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    
    print(head);
    
    insertInMiddle(head, 4, 3);
    print(head);
    
    insertAtTail(head, 7);
    print(head);

    deleteHead(head);
    print(head);


    return 0;
}