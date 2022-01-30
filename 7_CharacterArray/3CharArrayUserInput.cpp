//Char Array User input

#include <iostream>
using namespace std;

void ReadLine(char a[], char delimiter){
    int i = 0;
    char ch = cin.get();     // Statement

    while(ch != delimiter){   //print the char till the ch become delimiter
        a[i] = ch;
        i++;
        ch = cin.get();
    }
    a[i] = '\0';            //to terminater the loop
}
int main(){
    char a[100];
    
    ReadLine(a, '\n');      //delimiter is \n it can be any char

    cout << a << endl;

    cin.getline(a,100);     // same inbuilt function as ReadLine we make and default delimiter isn \n
    cout << a << endl;      //but for any other delimiter mention it in function last i.e. getline(a,5,'$')
}