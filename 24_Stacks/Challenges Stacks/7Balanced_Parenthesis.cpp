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


// You are given a string of brackets i.e. '{', '}' , '(' , ')', '[' , ']' . You have to check whether the sequence of parenthesis is balanced or not.
// For example, "(())", "(())()" are balanced and "())(", "(()))" are not.

// Input Format
// A string of '(' , ')' , '{' , '}' and '[' , ']' .

// Constraints
// 1<=|S|<=10^5

// Output Format
// Print "Yes" if the brackets are balanced and "No" if not balanced.

// Sample Input
// (())
// Sample Output
// Yes
// Explanation
// (()) is a balanced string.
