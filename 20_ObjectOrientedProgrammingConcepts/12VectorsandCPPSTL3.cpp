//vector ans C++ stl
//find the frequency of perticular in sorted array

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[] = {0, 1, 2, 2, 2, 2, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    //lower_bound fun return first that element addresses
    //for index number of that element subtract first arr address so (first - arr)
    auto first = lower_bound(arr, arr+n, 2) - arr;
    //upper_bound fun return element next to last elememnt 
    //for index of last element subtract last arr address - 1 so (last  - arr -1)
    auto last = upper_bound(arr, arr+n, 2) - arr - 1;

    cout << first << endl;
    cout << last << endl;

    cout << "total count of 2 is " << last - first + 1 << endl; 
    return 0;

}