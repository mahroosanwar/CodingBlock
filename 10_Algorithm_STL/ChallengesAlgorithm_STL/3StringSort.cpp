//String Sort lexicographically and greater length first

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b){
    int i = 0;
    while(a[i]==b[i]){
        i++;
    }
    if(a[i]=='\0'){
        return false;
    }
    else if(b[i]=='\0'){
        return true;
    }
    return a[i] < b[i];
}
int main(){
    int n;
    cin >> n;
    cin.get();
    string s[n];

    for(int i=0; i<n; i++){
        getline(cin, s[i]);
    }

    sort(s, s+n, compare);

    for(int i=0; i<n; i++){
        cout << s[i] << endl;
    }



    return 0;
}
