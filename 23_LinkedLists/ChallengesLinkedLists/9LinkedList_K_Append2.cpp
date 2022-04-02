//Linked List-K Append (method - 2)


#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertAtTail(Node *&head, int data, Node *&tail)
{
    if (head == NULL)
    {
        head = new Node(data);
        tail = head;
        return;
    }

    Node *n = new Node(data);

    tail->next = n;
    tail = n;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *kAppend(Node *head,int k)
{
    if(head==NULL or head->next==NULL or k==0)
    return head;
    Node* slow=head, *fast=head;

    while(k!=0)
    {
        fast=fast->next;
        k--;
    }
    if(fast==NULL)
    return head;

    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }

    Node* temp=slow;
    slow=slow->next;
    temp->next=NULL;

    fast->next=head;
    return slow;


}

int main()
{
    int data;
    int n;

    cin >> n;
    int n1 = n;
    Node *head = NULL;
    Node *tail = NULL;
    while (n1 !=0)
    {
        cin >> data;
        insertAtTail(head, data, tail);
        n1--;
    }

    int k;
    cin>>k;
    
    k = k%n;
    head=kAppend(head,k);
    print(head);

    return 0;
}