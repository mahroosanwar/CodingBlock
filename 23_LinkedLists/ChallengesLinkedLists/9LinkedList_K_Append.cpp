//Linked List-K Append

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

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

void builtList(node* &head, int n){
    
    for(int i=0; i<n; i++){
        int data;
        cin >> data;

        insertAtTail(head, data);
    }
}

node* LinkedList_K_Append(node* head, int k, int n){
    if(head == NULL || head->next == NULL){
        return head;
    }

    if(k == n){
        return head;
    }

    k = k%n;

    node* temp = head;

    for(int i=0; i<n-k-1; i++){         //n-k-1 bcz. stop one position prev from kth position form end
        temp = temp->next;
    }


    node* tail = temp->next;    

    while(tail->next != NULL){
        tail = tail->next;
    }
    
    node* temp2 = temp->next;

    temp->next = NULL;
    tail->next = head;
    
    return temp2;
}

int main(){
    node* head = NULL;
    int n;
    cin >> n;

    builtList(head, n);

    int k;
    cin >> k;
    head = LinkedList_K_Append(head, k, n);

    print(head);

    return 0;
}