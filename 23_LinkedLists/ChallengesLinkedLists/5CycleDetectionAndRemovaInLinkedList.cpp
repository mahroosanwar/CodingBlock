//Cycle Detection and Removal in Linked List

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

// head - Head pointer of the Linked List
// Return a boolean value indicating the presence of cycle
// If the cycle is present, modify the linked list to remove the cycle as well
bool floydCycleRemoval(Node *head)
{
    /* Code here */
    Node* fast = head;
    Node* slow = head;

    bool ans = false;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            ans = true;

            slow = head;

            while(slow != fast){
                fast = fast->next;
                slow = slow->next;
            }

            // u got the node which is making cycle now
            // just go to the node before it and open the cycle

            Node*prev = slow;

            while(prev->next != slow){
                prev = prev->next;
            }
            prev->next = NULL;
            break;
        }
    }
    return ans;
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

void buildCycleList(Node *&head)
{
    unordered_map<int, Node *> hash;
    int x;
    cin >> x;
    if (x == -1)
    {
        head = NULL;
        return;
    }
    head = new Node(x);
    hash[x] = head;
    Node *current = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            current->next = hash[x];
            return;
        }
        Node *n = new Node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = NULL;
}

void printLinkedList(Node *head)
{
    unordered_set<int> s;
    while (head != NULL)
    {
        if (s.find(head->data) != s.end())
        {
            cout << "\nCycle detected at " << head->data;
            return;
        }
        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    buildCycleList(head);

    bool cyclePresent = floydCycleRemoval(head);
    if (cyclePresent)
    {
        cout << "Cycle was present\n";
    }
    else
    {
        cout << "No cycle\n";
    }

    cout << "Linked List - ";
    printLinkedList(head);

    return 0;
}

// Given the head pointer to a linked list , complete the function to check whether there is a cycle present in the linked list. If so , modify the linked list to remove the cycle.

// Note : You are only supposed to update the designated function. Do not change/alter the remaining code or your program may not work.

// Input Format
// Your function accepts one single argument that is the head pointer to the linked list.

// Constraints
// Your function should run in O(n) time.

// Output Format
// Your function should return a boolean value - True/False , indicating the presence of the cycle.
// True if cycle is present, False otherwise.
// If true , remove the cycle as well.

// Sample Input
// Consider a linked list like 
// 1 -> 2 -> 3
//      ^    |
//      |    v
//      5<-  4
// Sample Output
// Your function should return True for the above linked list and remove the cycle as well. <br>
// The new linked list should look like - 1->2->3->4->5-> NULL
// Explanation
// Clearly there is a cycle present. We return true to indicate it and remove it.
