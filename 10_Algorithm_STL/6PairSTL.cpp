//Pair STL

#include <iostream>
using namespace std;

int main(){
    //1st Method of initilaization
    // pair<int, int>p;
    // p.first = 10;
    // p.second =101;
    
    //2st Method of initilaization
    //pair<int, int>p(500,200);  

    //3st Method of initilaization
    // pair<int, int>p;
    // p = make_pair(24,42);

    // pair<string, int>p;
    // p = make_pair("BMW", 10);

    // cout << "first: " << p.first << endl;
    // cout << "Second: " << p.second << endl;

    //Three Values together
    pair<string, pair<float, int> >p;
    p.first = "BMW";
    p.second.first = 10.11;
    p.second.second = 100;
    

    cout << p.first << endl;
    cout << p.second.first << endl;
    cout << p.second.second << endl;

    return 0;
}