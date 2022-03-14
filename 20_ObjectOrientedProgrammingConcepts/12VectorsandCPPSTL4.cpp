//Vectors and C++ STL

//wirte a sort fun for vector class and call inbuilt sort 
//fruit and price problem sort

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool myComp(pair<string, int> p1, pair<string, int> p2){
    if(p1.first.length() == p2.first.length()){
        return p1.first < p2.first;
    }
    return p1.first.length() < p2.first.length();
}

bool priceComp(pair<string, int> p1, pair<string, int> p2){
    return p1.second < p2.second; 
}
int main(){

    vector<pair<string, int> > v;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        int p;
        cin >> p;
        pair<string, int> myPair(s, p);
        v.push_back(myPair);
    }
    sort(v.begin(), v.end(), priceComp);
    for(auto p:v){
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
