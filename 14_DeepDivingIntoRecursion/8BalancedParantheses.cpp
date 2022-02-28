//Balanced Parantheses

#include <iostream>
using namespace std;

void BalancedParantheses(char *a, int n, int i, int o, int c){
    //base case
    if(i == 2*n){
        a[i] = '\0';
        cout << a << endl;
    }

    //recursive case

    if(o<n){
        a[i] = '(';
        BalancedParantheses(a, n, i+1, o+1, c);
    }
    if(o>c){
        a[i] = ')';
        BalancedParantheses(a, n, i+1, o, c+1);
    }

}
int main(){
    int n;
    cin >> n;
    char a[n];

    BalancedParantheses(a, n, 0, 0, 0);

    return 0;
}