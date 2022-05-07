//Functional Objects in C++

#include<iostream>
#include<cstring>
using namespace std;

class Fun {
public:
    void operator()(string s) {
        // cout << "Having Fun inside the Operator fn!";
        cout << "having fun with " << s;
    }
};

int main() {

    Fun f;  //constructor call

    f("C++");    //overloaded () operator = Function Call where f is an object call

    return 0;
}