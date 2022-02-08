//String sorting

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b){
    return a > b;
}

int main(){
    int n;
    cin >> n;

    string s[100];
    cin.get();

    for(int i=0; i<n; i++){
        getline(cin,s[i]);
    }

    //sorting
    sort(s, s+n, compare);      //compare function for desending order, default assending

    for(int i=0; i<n; i++){
        cout << s[i] << " ";
    }

    cout << endl;
}
