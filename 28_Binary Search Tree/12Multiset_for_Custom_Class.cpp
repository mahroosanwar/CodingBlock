//Multiset for Custom Class
//work in coding block not here

#include<iostream>
#include<set>
using namespace std;

//to print according to money
class person_compare{
public:
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        return p1.second < p2.second;
    }
};  

int main() {
    pair<string, int> p1 = make_pair("B", 100);
    pair<string, int> p2 = make_pair("A", 40);
    pair<string, int> p3 = make_pair("C", 120);
    pair<string, int> p4 = make_pair("D", 10);

    //Multiset

    //pair  - Name(string), Money(int)
    //costom data type

    // multiset<pair<string, int> >m;
    // m.insert(p1);
    // m.insert(p2);
    // m.insert(p3);
    // m.insert(p4);

    // //print with sorted according to the Name (string)
    // for(auto p:m) {
    //     cout << p.first << " and " << p.second << endl;
    // }

    //to print according to money(or second element)
    multiset<pair<string, int>, person_compare>m;       //here also define class(person_compare) in multiset
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);

    //print with sorted according to the Prince (int)
    for(auto p:m) {
        cout << p.first << " and " << p.second << endl;
    }

    return 0;
}