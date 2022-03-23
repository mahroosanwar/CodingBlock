//Merge Sorted Linked Lists

#include<iostream>
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

    node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void print(node*head){
    
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* merge(node*a, node*b){
    //base case
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }

    //rec case
    //take a head pointer
    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }

    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main(){
    int T; cin >> T;

    for(int i=0; i<T; i++){
        
        node*head1 = NULL;
        node*head2 = NULL;
        
        int n1; cin >> n1;
        
        for(int i=0; i<n1; i++){
            int data; cin >> data;
            insertAtTail(head1, data);
        }

        int n2; cin >> n2;

        for(int i=0; i<n2; i++){
            int data; cin >> data;
            insertAtTail(head2, data);
        }

        node* newHead = merge(head1, head2);

        print(newHead);
    }    
    return 0;
}
