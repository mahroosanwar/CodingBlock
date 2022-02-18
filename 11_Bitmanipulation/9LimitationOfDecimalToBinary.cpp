// Limitation of Decimal to Binary

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void DecimalToBinary(int n){
    string s;
    while(n>0){
        //s.push_back('0' + n%2); //it insert the value inside the string
        if(n%2==0){
            s.push_back('0');
        }
        else{
            s.push_back('1');
        }
        n/=2;  
    }
    reverse(s.begin(), s.end()); //it reverse the string 
    cout << s << endl;
}

int main(){
    int n;
    cin >> n;

    DecimalToBinary(n);

    return 0;
}
