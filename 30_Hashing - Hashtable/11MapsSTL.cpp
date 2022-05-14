//Maps STL

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    map<string, int> m;

    //1>1.Insert
    m.insert(make_pair("Mango", 100));

    //1>2.Insert
    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;

    m.insert(p);

    //1>3.Insert
    m["Banana"] = 20;

    //2>search

    string fruit;
    cin >> fruit;

    //4>Update the Price
    m[fruit] += 22;

    auto it = m.find(fruit);

    if(it != m.end()) {
        cout << "price of " << fruit << " is " << m[fruit] << endl;
    }
    else {
        cout << "Not Present" << endl;
    }

    //3>Erase
    m.erase(fruit);

    //another way to find perticular map
    //it stores unique only once 
    if(m.count(fruit)) {
        cout << "price is " << m[fruit] << endl;
    }
    else {
        cout << "not found " << endl; 
    }

    m["Lichi"] = 60;
    m["Pineapple"] = 80;

    //ite4rate over all the key value pairs
    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " and " << it->second << endl;
    }

    //for each loop
    for(auto p:m) {
        cout << p.first << " : " << p.second << endl;
    }

    
    return 0;
}