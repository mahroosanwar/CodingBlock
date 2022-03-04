//Convert String to Integer

#include <iostream>
using namespace std;

void Str_to_Int(string str, int i){
    //base case

    if(str[i] == '\0'){
        return;
    }

    // recursive case
    int digit = str[i] - '0';
    cout << digit;

    Str_to_Int(str, i+1);

}
int main(){
    string s;
    cin >> s;

    Str_to_Int(s, 0);

    return 0;
}