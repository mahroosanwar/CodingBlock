// Character Array Introduction

#include <iostream>
using namespace std;

int main(){
    char a[] = {'M','a','h','r','o','o','s','\0'};  // '\0' for end the string i.e. no garbage value
    cout << a;
    
    cout << endl;

    char b[10];
    b[0] = 'a';
    b[1] = 'b';
    
    cout << b;

    cout << endl;

    b[10];
    b[0] = 'a';
    b[1] = 'b';
    b[2] = '\0';
    cout << b;

    cout << endl;
    
    char c[] = "Mahroos Anwar";
    cout << c;
}
