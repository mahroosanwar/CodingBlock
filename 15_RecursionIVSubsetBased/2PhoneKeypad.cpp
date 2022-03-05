//PhoneKeypad

#include <iostream>
using namespace std;

string key[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void PhoneKeyboard(char *ip, char *op, int i, int j){
    //base case
    if(ip[i] == '\0'){
        op[j] = '\0';
        cout << op << " ";
        return;
    }

    //recursive case
    int digit = ip[i] - '0';

    for(int k = 0; key[digit][k] != '\0'; k++){
        op[j] = key[digit][k];
        PhoneKeyboard(ip, op, i+1, j+1);
    }
}

int main(){
    char ch[100];
    cin>> ch;

    char op[100];

    PhoneKeyboard(ch, op, 0, 0);

    return 0;
}
