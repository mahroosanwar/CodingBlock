// Even-After-Odd (method - 1)

#include<iostream>
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
    return;
}

void print(node* head){

    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void buildList(node* &head){
    int n;
    cin >> n;

    while(n--){
        int data;
        cin >> data;
        insertAtTail(head, data);
    }
}

node*  EvenAfterOdd(node* &head){
    node* oddHead = NULL, *oddTail = NULL, *evenHead = NULL, *evenTail = NULL;
    node* curr = head;

    while(curr != NULL){
        //if data if odd
        if(curr->data % 2 != 0){
            //it should be part of the left list

            if(oddHead == NULL){
                oddHead = oddTail = curr;
            }
            else{
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        //if data is even
        else{
            //it should be part of the right list
            
            if(evenHead == NULL){
                evenHead = evenTail = curr;
            }
            else{
                evenTail->next = curr;
                evenTail = curr;
            }
        }
        curr =  curr->next;
    }

    //corner case --> 
    if(oddHead == NULL){
        return evenHead;
    }

    if(evenHead == NULL){
        return oddHead;
    }

    //link left (odd) part to right (even) part
    evenTail->next = NULL;
    oddTail->next = evenHead;

    return oddHead;  
}

int main(){
    node* head = NULL;
    buildList(head);

    head = EvenAfterOdd(head);

    print(head);

    return 0;
}

// Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

// Input Format
// Enter N space separated Elements

// Constraints
// None

// Output Format
// Linked list with all the odd numbers before even numbers

// Sample Input
// 5
// 1 2 2 2 1
// Sample Output
// 1 1 2 2 2
