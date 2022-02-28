//String to int

#include <iostream>
#include <cstring>
using namespace std;

int StringToInt(string a, int n){
    //base case
    if(n==0){
        return 0;
    }

    //recursive case

    int digit = a[n-1] - '0';
    // int smallerAns = StringToInt(a, n-1);
    // int biggerAns = smallerAns*10 + digit;
    return StringToInt(a, n-1)*10 + digit;


}

int main(){
    char a[] = "4329";
    int n = strlen(a);

    int ans = StringToInt(a, n);

    cout << ans << endl;
    cout << ans + 1 << endl;

    return 0;
}
