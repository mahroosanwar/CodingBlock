//Bitwise operator 2 (check even / odd using bitwise operator)

#include <iostream>
using namespace std;

bool isOdd(int n){
    int lsb = ( n&1 ) == 0 ? 0 : 1;
    //lsb == 1 // non zero value means true
    //lsb == 0 // false
    return lsb;
}

bool check_ith(int n, int i){
    int mask = (1<<i);

    if((n&mask)){
        return true;
    }
    else{
        return false;
    }
}

void setbit_ith(int &n, int i){        //&n --> whatever changes makes inside the function will also refer to main
    int mask = (1<<i);
    n = (n|mask);

    cout << n << endl;
}

//if not use &n so do manually and call in main
int setbit_ith1(int n, int i){
    int mask = (1<<i);
    n = (n|mask);

    return n;
}


int main(){
    int n;
    cin >> n;

    if(isOdd(n)){
        cout << n << " is Odd";
    }
    else{
        cout << n << " is Even";
    }

    cout << endl;

    if(check_ith(n, 3)){
        cout << "3rd bit is " << 1 << endl;
    }
    else{
        cout << "3rd bit is " << 0 << endl;
    }

    setbit_ith(n, 3);

    cout << setbit_ith1(n,3);
    return 0;
}


