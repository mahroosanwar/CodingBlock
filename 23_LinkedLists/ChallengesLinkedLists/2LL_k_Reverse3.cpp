//LL_k_Reverse (where k may not be necessary is factor of N(total elements))
//and if remaining last element is less then k do not reverse them  

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
    //bases case
    if(head == NULL){
        return head;
    } 

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

        if(cnt == k){
            break;
        }
    }

    //for last remaining element count is less than k
    if(cnt < k){
        //undo the changes
        //reverse the list

        //curr ko waopis prev me le kr aana hai
        curr = prev;
        prev = NULL;

        while(curr != NULL){
            N = curr->next;
            curr->next = prev;

            prev = curr;
            curr = N;
        }
        return prev;
    }
    
    //rec solve for next kth elements
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