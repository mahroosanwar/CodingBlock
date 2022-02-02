//Take as input S, a string. Write a function that replaces every even character with
//the character having just higher ASCII code and every odd character with 
//the character having just lower ASCII code. Print the value returned.

#include <iostream>
using namespace std;

void OddEvenChar(char a[]){
    for(int i=0; a[i] != '\0'; i++){
        if(i%2 == 0){
            char x = a[i] + 1;
            cout << x;
        }
        else{
            char x = a[i] - 1;
            cout << x;
        }
    }
}
int main(){
    char a[1000];
    cin >> a;

    OddEvenChar(a);

    cout << endl;
    return 0;
}