//Take as input S, a string. Write a program that inserts between each pair of 
//characters the difference between their ascii codes and print the ans.

#include <iostream>
#include <cstring>
using namespace std;

void DiffInASCIIcode(char a[]){
    int len = strlen(a);
    int e = len-1;
    for(int i=1; a[i] != '\0'; i++){
        int x = a[i] - a[i-1];
        cout << a[i-1] << x;
    }
    cout << a[e] << endl;
}
int main(){
    char a[2000];
    cin>> a;

    DiffInASCIIcode(a);
    
    cout << endl;
    return 0;
}