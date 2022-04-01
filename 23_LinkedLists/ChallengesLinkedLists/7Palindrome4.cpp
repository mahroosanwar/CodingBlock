//Palindrome (method - 4)
#include<bits/stdc++.h>
using namespace std;
class node{
    public: 
    int data;
    node * next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
node * mid(node * head)
{
    node * temp=head;
    if(temp==NULL or temp->next==NULL)
    {
        return temp;
    }
    node * fast=temp->next;
    node * slow=temp;

    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node * reverselistrec(node * head)
{

    if(head->next==NULL or head==NULL)
    {
        return head;
    }
    node * smallhead=reverselistrec(head->next);
    
    head->next->next=head;
    head->next=NULL;

    return smallhead;
}
bool palindrome(node * head)
{
    node * midpoint=mid(head);
    midpoint->next=reverselistrec(midpoint->next);
    midpoint=midpoint->next;
    node * ptr=head;
    while(midpoint!=NULL)
    {
        if(ptr->data != midpoint->data)
        {
             return false;
        }
        midpoint=midpoint->next;
        ptr=ptr->next;
      }
      return true;
}
node * takeinput(int num)
{
    node * head=NULL;
    node * tail=NULL;
    while(num>0)
    {
         int data;
         cin>>data;
         node * n=new node(data);
         if(head==NULL)
         {
            head=n;
            tail=n;
        }
        else
        {
            tail->next=n;
            tail=n;
        }
        num--;
    }
    return head;
}
void print (node*head)
{
    node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    node * head=takeinput(n);

    if(palindrome(head)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;

}