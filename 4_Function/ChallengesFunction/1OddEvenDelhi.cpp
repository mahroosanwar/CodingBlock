// Odd even Delhi

#include <iostream>
using namespace std;

void Odd_Even(int no){
    int even_sum = 0, odd_sum = 0;
    while(no!=0){

        int rem = no%10;
        if(no%2 == 0){
            even_sum = even_sum + rem;
        }
        else{
            odd_sum = odd_sum + rem;
        }
        no/=10;
    }
    if(odd_sum%3 == 0 || even_sum%4 == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){
    int n, no;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> no;
        Odd_Even(no);
    }

    cout << endl;
    return 0;
}
