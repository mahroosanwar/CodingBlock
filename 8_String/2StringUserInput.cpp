//take user input of string

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    // string s;
    // cin >> s;
    // cout << s << endl;

    string s1;
    getline(cin, s1);       //default Delimiter '\n' 
    cout << s1 << endl;     // to use other Delimiter (cin, s, '$')

    string s3 = "World";
    string s2 = "Hello";
    if(s3 < s2){            //Dictionary order  (lexicographical)
        cout << s3 <<  " is smaller than " << s2;
    }
    else{
        cout << s2 << " is greater than " << s3;
    }

    cout << endl;

    cout << s2.compare(s3) << endl;     //if s2 = s3 it gives --> 0 else -ve and +ve
    
    return 0;
}