//Playing with Integers

#include <iostream>
using namespace std;

void Int_to_Dig(int n){
    //Base case
    if(n==0){
        return;
    }

    //recursive case

    string a[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int digit = n%10;
    Int_to_Dig(n/10);
    cout << a[digit] << " ";

}
int main(){
    int n;
    cin >> n;

    Int_to_Dig(n);

    return 0;
}