//Lexicographical Order

#include <bits/stdc++.h>
using namespace std;

void LexicographicalOrder_Nums(int n, int StartWith){
    //base case
    if(StartWith > n){
        return;
    }

    //recursive case
    cout << StartWith << " ";

    for(int i = 0; i <= 9; i++){
        int new_num = StartWith * 10 + i;
        LexicographicalOrder_Nums(n, new_num);
    }
}

int main(){
    int n;
    cin >> n;
    cout << "0 ";

    for(int i=1; i<=9; i++){
        LexicographicalOrder_Nums(n, i);
    }
    return 0;
}