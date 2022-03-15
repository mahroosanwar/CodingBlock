//Vectors 01 - Introduction

#include <iostream>
#include <vector>
using namespace std;

int main(){
    //how to create and intialize vector
    vector<int> a;
    vector<int> b(5, 10);   //5 int with value 10
    vector<int> c(b.begin(), b.end());
    vector<int> d{1, 2, 3, 4, 10, 14};

    //how to iterate over vector
    for(int i=0; i<c.size(); i++){
        cout << c[i] << " ";
    }

    cout << endl;

    for(auto it = b.begin(); it!=b.end(); it++){        //auto --> in this case ; " vector<int> :: iterator "
        cout << (*it) << " ";
    }
    cout << endl;

    //for each loop
    for(int x:d){
        cout << x << " ";
    }
    cout << endl;

    //discuss more function
    vector<int> v;
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int no;
        cin >> no;
        v.push_back(no);
    }

    for(int x:v){
        cout << x << " ";
    }
    cout << endl;
    //understand at memory level , what are the difference in the two
    
    cout << v.size() << endl;
    cout << v.capacity() << endl;       //size of underlying array
    cout << v.max_size() << endl;       //max. no. of element a vector can hold in the worst case according to avl memory in system
    
    cout << d.size() << endl;
    cout << d.capacity() << endl;       //size of underlying array
    cout << d.max_size() << endl;       //max. no. of element a vector can hold in the worst case according to avl memory in system


    return 0;
}
