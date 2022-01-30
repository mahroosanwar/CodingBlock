// Rotate String

#include <iostream>
#include <cstring>
using namespace std;

void RotateString(char a[], int n){
    int len = strlen(a);
    int i = len -1;
    while(i>=0){ 
        a[i+n] = a[i];
        i--;
    }
    i = 0;
    int j = len;
    while(i<n){
        a[i] = a[j];
        i++;
        j++;
    }
    a[len] = '\0';
}

int main(){
    char a[1000];
    int n;
    cin >> n;

    cin >> a;

    RotateString(a,n);
    cout << a;
}