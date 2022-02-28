//N Stairs

#include <iostream>
using namespace std;

int NStair(int n){
    //base case
    if(n<0){
        return 0;
    }
    if(n == 0){
        return 1;
    }

    //Recursive case

    return NStair(n-1) + NStair(n-2) + NStair(n-3);

}
int main(){
    int n;
    cin >> n;
    cout << NStair(n);

    return 0;


}