//Removing Consesutive Duplicates

#include <iostream>
#include <cstring>
using namespace std;

void RemoveDuplicate(char a[]){
    int i = 0, j = 1;
    int len = strlen(a);
    while(j<len){
        if(a[i] != a[j]){
            i++;
            a[i] = a[j];
        }
        j++;
    }
    a[i+1] = '\0';

    return;
}

int main(){
    char a[1000];
    cin.getline(a,1000);

    RemoveDuplicate(a);

    cout << a;
    
    return 0;
}