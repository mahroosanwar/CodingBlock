//Stacks 03 - Creating a Templated Class

#include <iostream>
#include <vector>
using namespace std;


template<typename T, /*typename U*/>
class Stack{

    //Stacks 02 - Implementation of Stack Data Structure using Vector
private:
    vector<T> v;
    // vector<U> v2;            //we can create two vector of diff. class just make templete U

public:
    void push(T data){
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
    T top(){
        return v[v.size() - 1];
    }

};

int main(){
    Stack<int> s;     //when templete class created so decleare what type of Stack 's' class is created as here 'int' ;   
    // Stack<char, int> s;      //for two vector in same class

    // take input
    for(int i = 1; i<=5; i++){
        s.push(i*i);
    }

    //print the element of stack by poping each element
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    Stack<char> s1;

    // take input
    for(int i = 65; i<=70; i++){
        s1.push(i);
    }

    //print the element of stack by poping each element
    while(!s1.empty()){
        cout << s1.top() << " ";
        s1.pop();
    }

    return 0;
}