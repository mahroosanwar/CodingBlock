//Lower and Upper Bound

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[] = {10, 20, 40, 40, 50};
    int n = sizeof(a)/sizeof(int);

    int key;
    cin >> key;
    
    //lower bound

    int*ans = lower_bound(a, a+n, key);

    int indx = ans-a;
    cout << "Key found at: " << indx << endl;
    
    return 0;
}