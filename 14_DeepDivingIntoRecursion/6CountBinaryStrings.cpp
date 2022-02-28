//Count Binary Strings without consecutive 1's

#include <iostream>
using namespace std;

int CountBinaryStrings(int n, int ld){
    //base case
    if(n==1){
        if(ld == 0)return 2;

        else return 1;
    }

    //recursive case

    if(ld == 0){
        return CountBinaryStrings(n-1,1) + CountBinaryStrings(n-1,0);
    }
    else{
        return CountBinaryStrings(n-1, 0);
    }

}
int main(){
    int n;
    cin >> n;

    cout << CountBinaryStrings(n, 0);

    return 0;
}