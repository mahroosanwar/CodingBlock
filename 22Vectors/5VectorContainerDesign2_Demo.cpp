#include <iostream>
#include "5VectorContainerDesign.h"
using namespace std;

int main(){
    vector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.pop_back();
    v.push_back(6);
    v.push_back(10);

    cout << "Capacity " << v.capacity() << endl;
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}