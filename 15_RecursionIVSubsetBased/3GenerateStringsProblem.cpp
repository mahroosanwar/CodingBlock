//GenerateStrings Problem

#include <iostream>
using namespace std;

void GenerateStrings(char *ip, char *op, int i, int j){
    //base case
    if(ip[i] == '\0'){
        op[j] = '\0';
        cout << op << " ";
        return;
    }

    //recursive case
    //1--> let's take first digit
    int fd = ip[i] - '0';
    char ch = 'A' + fd - 1;
    op[j] = ch;

    GenerateStrings(ip, op, i+1, j+1);

    //2--> let's take two digit
    if(ip[i+1] != '\0'){
        int sd = ip[i+1] - '0';
        int no = 10*fd + sd;
        
        if(no <= 26){
            char ch = 'A' + no - 1;
            op[j] = ch;
        GenerateStrings(ip, op, i+2, j+1);
        }
    }
}

int main(){
    char ip[100], op[100];
    cin >> ip;

    GenerateStrings(ip, op, 0, 0);

    return 0;
}