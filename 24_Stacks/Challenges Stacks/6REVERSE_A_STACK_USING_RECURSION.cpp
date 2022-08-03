//REVERSE A STACK USING RECURSION

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }

    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
}

void reverseStack(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    //otherwise
    //pop out top enelment and insert insert it at the bottom of the 'reversed smaller stack' 
    int x = s.top();
    s.pop();

    //rec case for smaller stack
    reverseStack(s);
    insertAtBottom(s, x);        
}

int main(){
    
    int n;
    cin >> n;

    stack<int> s;
    for(int i=0; i<n; i++){
        int data;
        cin >> data;
        s.push(data);
    }

    reverseStack(s);
        
    //print the element of stack by poping each element
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}



// Reverse a Stack using Recursion. Do not use any extra stack.

// Input Format
// First line contains an integer N (size of the stack).
// Next N lines follow each containing an integer to be stored in the stack where the last integer is at the top of the stack.

// Constraints
// 1 <= N <= 10^4

// Output Format
// Output the values of the reversed stack with each value in one line each.

// Sample Input
// 3
// 3
// 2
// 1
// Sample Output
// 3
// 2
// 1
// Explanation
// Original Stack = [ 3 , 2 , 1 ] <-TOP
// Reverse Stack = [ 1 , 2 , 3 ] <-TOP
