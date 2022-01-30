//check palindrome of String

#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char a[]){
    int i=0, j = strlen(a) - 1;
    while(i<j){
        if(a[i] != a[j]){
            return false;
        }
        i++,j--;
    }
    return true;
}

int main(){
    char a[1000];
    cin >>a;

    if(isPalindrome(a)){
        cout << a << " is palindrome" << endl;
    }
    else{
        cout << a << " is not palindrome" << endl;
    }

    return 0;
}