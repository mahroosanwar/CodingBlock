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