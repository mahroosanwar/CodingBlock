//Print Increasing Numbers

#include <iostream>
using namespace std;

void PrintIncr(int i, int n){
    if(i==n+1){
        return;
    }
    cout << i << " " ;
    PrintIncr(i+1,n);
}

int main(){
    int n;
    cin >> n;

    PrintIncr(1,n);

    return 0;
}