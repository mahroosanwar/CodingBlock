// LL - k Reverse (where k is the factor of N(total elements))

#include <bits/stdc++.h>
using namespace std;

class Node{
    public :
    int data;
    Node*next;

    Node(int _data){
        data = _data;
        next = NULL;
    }
};

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void insert(Node*&head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }

    Node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = new Node(d);
    return;
}

int n;
Node*take_input(){
    int d;
    Node*head = NULL;
    while(n--){
        cin>>d;
        insert(head,d);
    }
    return head;
}

void reverse(Node*&head){
   Node*current = head;
   Node*prev = NULL;

   while(current!=NULL){
       Node* after_current = current->next;
       current->next = prev;
       prev = current;
       current = after_current;
   }
   head = prev;
}

Node* recReverse(Node*head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    Node* shead = recReverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return shead;
}

Node*th = NULL;
Node*tt = NULL;
Node*oh = NULL;
Node*ot = NULL;

void addFirst(Node*node){
    if(th==NULL){
        th = node;
        tt = node;
    }
    else{
        node->next = th;
        th = node;
    }
}

void reverse_add_first(Node*head){
    while(head!=NULL){
        Node*after=head->next;
        head->next = NULL;
        addFirst(head);
        head=after;
    }
}

int len_(Node*head){
    int cnt=0;
    while(head!=NULL){
        head=head->next;
        cnt++;
    }
    return cnt;
}

Node* Kreverse(Node*head, int k){
    if(head==NULL or head->next==NULL or k<=1){
        return head;
    }

    int length = len_(head);

    Node* curr = head;

    while(length>=k){
        int t = k;
        while(t--){
            Node* after = curr->next;
            curr->next = NULL;
            addFirst(curr);
            curr = after;
        }

        if(oh == NULL){
            oh = th;
            ot = tt;
        }
        else{
            ot->next = th;
            ot = tt;
        }
        th = NULL;
        tt = NULL;

        length -= k;
    }

    return oh;
}

int main(){
    int k;
    cin>>n>>k;
    Node* head = take_input();
    head = Kreverse(head,k);
    print(head);
}