//Balanced Parenthesis

#include<iostream>
#include<stack>
using namespace std;

bool isValidExp(char * s){
    stack<char> stk;

    for(int i=0; i<s[i] != '\0'; i++){
        char ch = s[i];

        if(ch=='('){
            stk.push(ch);
        }
        else if(ch==')'){
            if(stk.empty() || stk.top() != '('){
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main(){
    char ch[100] = "((a+b)+(c-d+f))";
    if(isValidExp(ch)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}
