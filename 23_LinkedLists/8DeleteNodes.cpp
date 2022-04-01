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