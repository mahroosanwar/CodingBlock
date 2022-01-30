//Iterating over Array of String

#include <iostream>
using namespace std;

int main(){
    char a[100];
    cin >> a;       //take input

    cout << '\n' << a << endl;

    for(int i = 0; a[i] != '\0'; i++){
        cout << a[i] << " ";                //cin ignore white spaces so not work for "ABC DEF"
    } 
}