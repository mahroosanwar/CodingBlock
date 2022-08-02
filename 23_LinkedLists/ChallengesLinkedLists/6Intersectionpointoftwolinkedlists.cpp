// Intersection point of two linked lists

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// This function gets two arguments - the head pointers of the two linked lists
// Return the node which is the intersection point of these linked lists
// It is assured that the two lists intersect
Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
    /*Code here*/
    int len1 = 0, len2 = 0;
    Node* temp1 = l1, *temp2 = l2;

    while(temp1 != NULL){
        len1++;
        temp1 = temp1->next;
    }

    while(temp2 != NULL){
        len2++;
        temp2 = temp2->next;
    }

    temp1 = l1;
    if(len1>len2){
        int rem = len1-len2;
        while(rem--){
            temp1 = temp1->next;
        }
    }

    temp2 = l2;
    if(len1<len2){
        int rem = len2 - len1;
        while(rem--){
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2){
            return temp1;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;

}

/*
*
*
*   You do not need to refer or modify any code below this. 
*   Only modify the above function definition.
*	Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*	You do not even need to read or know about the code below.
*
*
*
*/

Node *buildList(unordered_map<int, Node *> &hash)
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *current = head;
    hash[x] = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        Node *n = new Node(x);
        hash[x] = n;
        current->next = n;
        current = n;
    }
    current->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    unordered_map<int, Node *> hash;
    Node *l1 = buildList(hash);

    Node *l2 = NULL;
    int x;
    cin >> x;
    l2 = new Node(x);
    Node *temp = l2;

    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            temp->next = hash[x];
            break;
        }
        Node *n = new Node(x);
        temp->next = n;
        temp = n;
    }

    cout << "L1 - ";
    printLinkedList(l1);
    cout << "L2 - ";
    printLinkedList(l2);

    Node *intersectionPoint = intersectionOfTwoLinkedLists(l1, l2);
    cout << "Intersection at node with data = " << intersectionPoint->data << endl;

    return 0;
}

// Given two intersecting linked lists, write a function to find its point of intersection. If the lists do not intersect , return NULL.

// Note : You are required to only write a single function. Do not modify / alter the remaining code.

// This is a stub problem so you need not worry about taking input or displaying output. Only focus on the designated function.

// Input Format
// You are given a function which accepts head pointers of two linked lists.

// Constraints
// Your function should run in linear time.

// Output Format
// Return the intersection point node.

// Sample Input
// Consider these linked lists :
// 1 -> 2 -> 3  -> null
//    ↗
// 4

// (This is not the actual input that will be provided but rather a description of it)
// Sample Output
// The two linked lists 1->2->3->null and 4->2->3-> null intersect at node with data 2.
// Return the node with data = 2.
// Explanation
// The two linked lists intersect at 2. Return their intersection point.
