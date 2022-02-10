//Binary search STL function

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[] = {5, 4, 8, 10, 6};
    int n = sizeof(a)/sizeof(int);

    int key;
    cin >> key;

    sort(a, a+n);

    bool present = binary_search(a, a+n, key);   
    if(present){
        cout << "key found" ;
    }
    else{
        cout << "key not found";
    }
    return 0;
}