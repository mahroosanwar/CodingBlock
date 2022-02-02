#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char a[]){
    int len = strlen(a);
    int i = 0;
    while(i<len){
        if(a[i] != a[len-1]){
            return false;
        }
        i++, len--;
    }
    return true;
}

int main()
{
    char a[1000];
    cin >> a;

    if(isPalindrome(a)){
        cout << "true";
    }
    else{
        cout << "false";
    }

    cout << endl;
    return 0;
}
