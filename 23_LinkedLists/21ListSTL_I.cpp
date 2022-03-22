//List STL - I

#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l;

    //initialization 
    list<int> l1 = {1, 2, 3, 10, 8, 5};
    
    //different data type
    list<string> l2 = {"apple", "guava", "mango", "banana"};
    l2.push_back("pineapple");      //insert at the tail

    //calling sort that is available inside the list class
    l2.sort();

    //reverse the order
    l2.reverse();

    //call from front
    cout << l2.front() << endl;
    //remove from front
    l2.pop_front();

    //add to the front of the list
    l2.push_front("kiwi");
    cout << l2.back() << endl;
    l2.pop_back();

    //iterate over the list and print it
    for(auto it = l2.begin(); it != l2.end(); it++){
        cout << (*it) << "-->";
    }
    
    cout << endl;

    for(auto s:l2){
        cout << s << "-->" ;
    }

    return 0;
}