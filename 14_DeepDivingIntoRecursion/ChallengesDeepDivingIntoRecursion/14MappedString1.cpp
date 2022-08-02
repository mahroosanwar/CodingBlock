//Codes of The string Method 1


#include <iostream>
using namespace std;

void GenerateStrings(char *ip, char *op, int i, int j){
    //base case
    if(ip[i] == '\0'){
        op[j] = '\0';
        cout << op << endl;
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

// We are given a hashmap which maps all the letters with number. Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z. Given a number, you have to print all the possible strings.

// Input Format
// A single line contains a number.

// Constraints
// Number is less than 10^6

// Output Format
// Print all the possible strings in sorted order in different lines.

// Sample Input
// 123
// Sample Output
// ABC
// AW
// LC
// Explanation
// '1' '2' '3' = ABC
// '1' '23' = AW
// '12' '3' = LC
