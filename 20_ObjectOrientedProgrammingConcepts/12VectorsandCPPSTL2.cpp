//12_Vectors_and_CPP_STL_2.cpp

#include <iostream>
#include <set>
using namespace std;

int main(){
    //1--> store elements in sorted order
    //2--> unique elements: each repeating elements occurs only once

    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(3);

    for(auto x:s){
        cout << x  << " ";
    }

    cout << endl << s.size() << endl;
    // s.clear();               //it will clear the set
    // cout << s.size() << endl;
    
    //iterator like use pointer
    for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
        cout << (*it) << " ";
    }
    return 0;
}

