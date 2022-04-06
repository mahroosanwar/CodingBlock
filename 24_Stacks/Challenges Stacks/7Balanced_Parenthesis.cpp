//Balanced Parenthesis

#include<iostream>
#include<stack>
using namespace std;

bool isBalance(char *s){
    stack<char> stk;

    for(int i=0; i<s[i] != '\0'; i++){
        char ch = s[i];

        if(ch == '('){
            stk.push(ch);
        }
        else if(ch == ')'){
            if(stk.empty() || stk.top() != '('){
                return false;
            }
            stk.pop();
        }
        
        if(ch == '{'){
            stk.push(ch);
        }
        else if(ch == '}'){
            if(stk.empty() || stk.top() != '{'){
                return false;
            }
            stk.pop();
        }


        if(ch == '['){
            stk.push(ch);
        }
        else if(ch == ']'){
            if(stk.empty() || stk.top() != '['){
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main(){
    char ch[1000];
    cin >> ch;

    if(isBalance(ch)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}