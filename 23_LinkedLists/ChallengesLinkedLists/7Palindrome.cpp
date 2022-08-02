//Palindrome  Linked List (method 1)

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

void buildList(node* &head){
    int n;
    cin >> n;

    while(n--){
        int data;
        cin >> data;

        insertAtTail(head, data);
    }
}

node* recReverse(node* head){

    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //rec case

    node* smallHead = recReverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return smallHead;
}

bool isPlaindrome(node* head, node* revHead){
    while(head != NULL){

        if(head->data == revHead->data){
            head = head->next;
            revHead = revHead->next;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    node* head = NULL;
    buildList(head);

    node* reverse_Head = recReverse(head);

    if(isPlaindrome(head, reverse_Head)){
        cout << "true";
    }
    else{
        cout << "false";
    }

    return 0;
}

// Check if a linked list is a palindrome.( Boolean return type )

// Input Format
// Add N space separated elements in the list

// Constraints
// None

// Output Format
// Boolean answer( true or false)

// Sample Input
// 5
// 1 2 3 6 8
// Sample Output
// false
