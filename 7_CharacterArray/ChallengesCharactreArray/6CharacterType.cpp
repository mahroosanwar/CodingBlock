//Character Type LowerCase(L) , Upperase(U), or Invalid(I)

#include <iostream>
using namespace std;

void CharacterType(char a){
    if(a >='A' && a<='Z'){
       cout << 'U' << endl; 
    }
    else if(a >= 'a' && a<= 'z'){
        cout << 'L' << endl;
    }
    else{
        cout << 'I' << endl;
    }
}
int main(){
    char a;
    cin >> a;

    CharacterType(a);

    cout << endl;
    return 0;
}


// Take the following as input.

// A character (ch) Write a function that returns ‘U’, if it is uppercase; ‘L’ if it is lowercase and ‘I’ otherwise. Print the value returned.

// Input Format
// Character (ch)

// Constraints
// No constraints

// Output Format
// 'L' (if ch is lower-case) 'U' (if ch is upper-case) 'I' (otherwise)

// Sample Input
// s
// Sample Output
// L
// Explanation
// Anyone can Do it using Ascii codes. I dare you - "Try to not use ascii codes." ;)
