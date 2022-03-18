//Linked List 09 - Recursive Reverse a Linked List

//Linked List 08 - Reverse a Linked List

//Linked List 07 - Operator Overloading

// Linked List 06 - Taking Input

// Linked List 05 - Searching

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

//searching operation
//Linear Search

bool search(node*head, int key){
    node* temp = head;
    while(temp!= NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//recursive search
bool searchRecursive(node*head, int key){
    if(head == NULL){
        return false;
    }

    //rec case check at head, remaining link list
    if(head->data == key){
        return true;
    }
    else{
        return searchRecursive(head->next, key);
    }
}

//input from user ; 2--> ways
//either by passing head to take input function and adding nodes to head of the Linked List 
// void take_input(node*&head){

// }

//otherwise you can create a new head pointer inside the take ip function and return that head pointer to the main
node* take_input(){
    int d;
    cin >> d;

    node*head = NULL;
    while(d != -1){
        insertAtHead(head, d);
        cin >> d;
    }
    return head;
} 

//take input from the file (ex.  .txt)
node* take_input_2(){
    int d;
    node*head = NULL;

    while(cin >> d){            //till the number in file this will run
        insertAtHead(head, d);
    }
    return head;
}

//work as cout 
ostream& operator<<(ostream &os, node*head){
    print(head);
    return os;
}

//work as cin ;  //here head passing by reference as we take input we need to modify the linked list
istream& operator>>(istream &is, node*&head){ 
    head = take_input();
    return is;
}

//here head passing by reference as we take input we need to modify the linked list
void reverse(node*&head){
    node*curr = head;
    node*prev = NULL;
    node* N;

    while(curr != NULL){
        //save the next node
        N = curr->next;
        //make the curr node point to previous
        curr->next = prev;

        //update prev and curr take them 1 step forward
        prev = curr;
        curr = N;
    }
    head  = prev;
}

//O(N^2) time complexity of this recReverse() 
// node* recReverse(node*head){            
//     //smallest linked list ; 1 node or 0 node
//     if(head->next == NULL /*if LL have one node*/ || head == NULL /*no node*/){
//         return head;
//     }

//     //rec case
//     node* shead = recReverse(head->next);

//     node* temp = shead;
//     while(temp->next != NULL){
//         temp = temp->next;
//     }
//     head->next = NULL;
//     temp->next = head;
//     return shead;
// }

//optimize way to rec function
node* recReverse(node*head){            
    //smallest linked list ; 1 node or 0 node
    if(head->next == NULL /*if LL have one node*/ || head == NULL /*no node*/){
        return head;
    }

    //rec case
    node* shead = recReverse(head->next);

    // node* temp = head->next;        //by making this; optimize
    // temp->next = head;
    head->next->next = head;
    head->next = NULL;
    return shead;
}

int main(){

    node*head;
    cin >> head;
    cout << head << endl;
    head = recReverse(head);
    cout << head << endl;

    return 0;
}