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