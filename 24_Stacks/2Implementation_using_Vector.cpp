//Stacks 02 - Implementation using Vector

#include <iostream>
#include <vector>
using namespace std;

class Stack{

    //Stacks 02 - Implementation of Stack Data Structure using Vector
private:
    vector<int> v;

public:
    void push(int data){
        v.push_back(data);
    }
    
    bool empty(){
        return v.size() == 0;
    }

    void pop(){
        if(!empty()){
            v.pop_back();
        }
    }

    //last elememt
    int top(){
        return v[v.size() - 1];
    }

};

int main(){
    Stack s;

    // take input
    for(int i = 1; i<=5; i++){
        s.push(i*i);
    }

    //print the element of stack by poping each element
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }


    return 0;
}
