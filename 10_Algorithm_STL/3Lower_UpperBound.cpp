//Lower and Upper Bound

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[] = {10, 20, 40, 40, 40, 50, 60, 100};
    int n = sizeof(a)/sizeof(int);

    int key;
    cin >> key;
    
    //lower bound (first occurance of key)

    int*ans = lower_bound(a, a+n, key);     //return address of >= key

    int indx = ans-a;
    cout << "key: " << *ans << endl;
    cout << "Key found at(first occurance): " << indx << endl;

    //Upper bound (last occurance of Key)
    int *x = upper_bound(a, a+n, key);      //return address of >key
    int index = x-a-1;
    cout << "key: " << *x << endl;
    cout << "key found at(last occurance): " << index << endl;      

    cout << "no of occurance of key " << x-ans << endl;
    return 0;
}
