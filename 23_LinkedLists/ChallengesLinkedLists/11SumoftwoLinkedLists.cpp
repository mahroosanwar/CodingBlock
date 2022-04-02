//Sum of two Linked Lists

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
    int i = 0;
    while(i<n){
        int data;
        cin >> data;
        insertAtTail(head, data);
        i++;
    }
} 

node* RecReverse(node* head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //rec case

    node* smallHead = RecReverse(head->next);

    head->next->next = head;
    head->next = NULL;
    return smallHead;

}

node* SumoftwoLinkedLists(node* head1, node* head2, int carry){
    
    //base case
    if(head1 == NULL && head2 == NULL){
        if(carry>0){
            return new node(carry);
        }
        return NULL;
    }

    //rec case

    // if a node is null, we consider its value as 0
    int value1 = (head1 != NULL) ? head1->data : 0;
    int value2 = (head2 != NULL) ? head2->data : 0;
    
    // calculate sum and carry by using values of corresponding nodes 
    int sum  = (value1 + value2 + carry) % 10;
    carry  = (value1 + value2 + carry) / 10;

    // create a new node with value as sum.
    node* currentHead = new node(sum);

    // get the next nodes for respective linked lists
    node* NextHead1 = (head1 != NULL) ? head1->next : NULL;
    node* NextHead2 = (head2 != NULL) ? head2->next : NULL;

    // now add list segments after head1 and head2. 
    // append the result to currentHead(obtained by adding head1 and head2)
    currentHead->next = SumoftwoLinkedLists(NextHead1, NextHead2, carry); 
    return currentHead;
}

int main(){
    int N, M;
    cin >> N >> M;

    node* head1 = NULL;
    node* head2 = NULL;

    builtList(head1, N);
    builtList(head2, M);

    head1 = RecReverse(head1);
    head2 = RecReverse(head2);

    node* sum = SumoftwoLinkedLists(head1, head2, 0);
    sum = RecReverse(sum);
    print(sum);

    return 0;
}