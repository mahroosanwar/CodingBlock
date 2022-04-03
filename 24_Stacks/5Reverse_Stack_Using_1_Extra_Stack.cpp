//Stacks 05 - Reverse Stack Using 1 Extra Stack

#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){           //where n is n-1-i

    for(int i=0; i<n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1){
    //helper stack
    stack<int> s2;

    int n = s1.size();

    for(int i=0; i<n; i++){
        //pick the element from top and insert it at the bottom
        int x = s1.top();
        s1.pop();

        // transfer n-1-i element from s1 to  s2
        transfer(s1, s2, n-1-i);

        //insert the element x in s1
        s1.push(x);

        // transfer n-1-i element from s1 to  s2
        transfer(s2, s1, n-1-i);
    }
}

int main(){
    stack<int> s;

    for(int i=1; i<=5; i++){
        s.push(i);
    }
    reverseStack(s);

    //print
    cout << "after reverse" << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}