//Multiset STL

#include<iostream>
#include<set>
using namespace std;

//define a new datatype
typedef multiset<int>::iterator It;

int main() {
    //Multiset - that acn store multiple elements that have same elements
    //stored in a specific -> sorted according to internal comparision object
    //values once inserted can not be modified 
    //it is a associative container -> means if you want to refer element you have to refer by key/value (element are refer by their values not by their index)
    //underlying implementation is BST

    int arr[] = {10, 20, 30, 20, 30, 30, 30, 10, 30};
    int n =sizeof(arr)/sizeof(int);
    multiset<int> m(arr, arr+n);

    //erase - 20
    m.erase(20);

    //insert
    m.insert(80);

    //Iterator
    for(int x:m) {
        cout << x << " ";
    }

    //count element frequency
    cout << "\nCount " << m.count(10) << endl; 

    //find
    auto it = m.find(30);       //get an iterator to element 30 so it give 1st occurance
    cout << *(it) << endl;

    //Got all elements which are equal of 30;
    pair<It, It> range = m.equal_range(30);      //this will iterate ove rall elements which are equal to 30

    for(auto it = range.first; it!=range.second; it++) {
        cout << *(it) << " ";
    }
    cout << endl;


    //lower_bound and upper_bound
    for(auto it = m.lower_bound(10); it!=m.upper_bound(77); it++) {
        cout << *it << " ";
    }

    return 0; 
}