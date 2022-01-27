//Print all prime no using function

#include <iostream>
using namespace std;

void PrintPrimes(int n){
    int i,no;

    for(no = 2; no<=n; no++){
        for(i = 2; i<no; i++){
            if(no%i==0){
                break;
            }
        }
        if(i==no){
            cout << no << " "; 
        }
    }
}

int main(){
    int n;
    cin >> n;

    PrintPrimes(n);

    cout << endl;

    PrintPrimes(20);
    cout << endl;
    return 0;
}