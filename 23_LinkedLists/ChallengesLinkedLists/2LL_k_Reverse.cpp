// LL - k Reverse (where k is the factor of N(total elements))

#include <iostream>
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

void insertAtTail(node*&head, int data){
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

void print(node*head){
    
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* LL_K_Reverse(node*&head, int k){

    //reverse first k elements

    node* curr = head;
    node* prev = NULL;
    node* N;
    int cnt = 0;

    while(curr != NULL && cnt < k){
        
        //save the next node
        N = curr->next;
        //make the curr node point to previous
        curr->next = prev;

        //update prev and curr take them 1 step forward
        prev = curr;
        curr = N;

        cnt++;
    }

    //rec solve for next kth elements
    if(N != NULL)
    head->next = LL_K_Reverse(curr, k);         //now new head become curr

    return prev;        //prev become new head so return it
}

int main(){
    node* head = NULL;
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        int data; cin >> data;
        insertAtTail(head, data);
    }

    head = LL_K_Reverse(head, k);

    print(head);
    return 0;
}

// Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

// You need not have to create a new list. Just reverse the old one using head.

// Input Format
// The first line contains 2 space separated integers N and K

// The next line contains N space separated integral elements of the list.

// Constraints
// 0 <= N <= 10^6 0 <= K <= 10^6

// Output Format
// Display the linkedlist after reversing every k elements

// Sample Input
// 9 3
// 9 4 1 7 8 3 2 6 5
// Sample Output
// 1 4 9 3 8 7 5 6 2
// Explanation
// N = 9 & K = 3

// Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5

// After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2
