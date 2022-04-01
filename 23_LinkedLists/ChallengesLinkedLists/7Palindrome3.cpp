//Palindrome 3 (method  - 3)

#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
};


//inserting node at the end
void insertAtTail(node *&head , int data){

    if(head == NULL){
        head = new node(data);
        return;
    }

    node *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp->next = new node(data);
}

bool is_palindrome(node *head,int n){
    node *temp1 = head;
    int j=1;
    int pos = n;
    while(j<=n/2){
        node *start =temp1;
        node *temp = start;
        int i=1;
        while(i<pos){
            temp = temp -> next;
            i++;
        }
        node *end = temp;
        if(start->data != end->data){
            return false;
        }
        j++;
        temp1 = temp1 -> next;
        pos=pos-2;
    }
    return true;
}


//Building Linked list By taking input from user
void buildList(node *&head,int n){
    int i=0;

    while(i<n){
        int data;
        cin>>data;
        insertAtTail(head,data);
        i++;
    }
}

int main() {
    node *head = NULL;
    int n;
    cin>>n;

    buildList(head,n);

    bool ans = is_palindrome(head,n);
    if(ans== true){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

return 0;
}