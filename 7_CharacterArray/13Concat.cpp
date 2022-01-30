//Concatination two string

#include <iostream>
#include <cstring>

using namespace std;
void concat(char a[], char b[]){
    int i = strlen(a);
    int lenb = strlen(b);

    for(int j=0; j<=lenb; j++){
        a[i] = b[j];
        i++;
    } 
}
int main(){
    char a[2000];
    char b[1000];

    cin.getline(a,1000);
    cin.getline(b,1000);

    // concat(a,b);

    // cout << a << endl;
    // cout << b << endl;

    //this function append string b to a
    strcat(a,b);

    cout << a << endl;

    cout << endl;
    return 0;
}