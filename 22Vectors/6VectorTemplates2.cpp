#include <iostream>
#include "6VectorTemplates.h"
using namespace std;

int main(){
    // vector<int> v;
    vector<char> v;

    v.push_back(70);
    v.push_back(72);
    v.push_back(73);
    v.push_back(74);
    v.pop_back();
    v.push_back(76);
    v.push_back(80);

    cout << "Capacity " << v.capacity() << endl;
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}