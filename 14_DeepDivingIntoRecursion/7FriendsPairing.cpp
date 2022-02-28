//Friends Pairing

#include <iostream>
using namespace std;

int FriendsPairing(int n){
    //base casse

    if(n==0 || n==1)return 1;

    //recursive case
    return FriendsPairing(n-1) + (n-1)*FriendsPairing(n-2);
}

int main(){
    int n;
    cin >> n;

    cout << FriendsPairing(n);
    
    return 0;
}