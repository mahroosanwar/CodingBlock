//Vectors 02 - Methods

#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> d{1, 2, 3, 10, 14};
    d.push_back(16);        //push_back O(1) most of the time

    for(int x:d){
        cout << x << " ";
    }
    cout << endl;
    //remove the last element ; O(1)
    d.pop_back();
    for(int x:d){
        cout << x << " ";
    }
    cout << endl;

    //insert some element in the middle; O(N) -->  N denotes no of element we added + no of element you have shifted 
    d.insert(d.begin()+3, 4, 100);

    for(int x:d){
        cout << x << " ";
    }
    cout << endl;
    //erase some element in the middle
    d.erase(d.begin() + 3);
    for(auto x:d){
        cout << x << " ";
    }
    cout << endl;

    d.erase(d.begin()+3, d.begin()+5);
    for(int x:d){
        cout << x << " ";
    }

    //delete all the element from vector -->  it doesn't delete the memory
    d.clear();
    for(int x:d){
        cout << x << " ";
    }

    cout << endl;
    d.push_back(10);
    d.push_back(11);
    d.push_back(12);

    cout << d.front() << endl;      //return first element of the vector
    cout << d.back() << endl;       //return last elememt of the vector


    int n; cin >> n;
    vector<int> v;
    //reserve ; to avoid doubling (for large size it become slow)
    v.reserve(1000);
    int no = 0;
    for(int i=0; i<n; i++){
        // int no;
        // cin >> no;
        no++;
        v.push_back(no);
        cout << "changing capacity " << v.capacity() << endl;
    }
    cout << "Capacity " << v.capacity() << endl;
    for(int x:v){
        cout << x << " ";
    }
    return 0;
}