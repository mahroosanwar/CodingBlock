//Introduction of String

#include <iostream>
#include <string>
using namespace std;

int main(){
    // Initialization

    string s = "Hello";
    cout << s << endl;

    for(int i=0; i < s.length(); i++){
        cout << s[i] << " ";
    }
    cout << endl;

    //2nd way
    string s2 = s;
    cout << s2 << endl;

    //3rd Way
    string s3 = s2;
    cout << s3 << endl;

    //charcter array to string
    char a[] = "Hello World!";
    string s4(a);
    cout << s4 << endl;

    string x = "Hello";
    string y = "World for learning";

    //concat
    x = x + " " + y;
    cout << x << endl;
    
    x += y;             //+= operator can be also used
    cout << x << endl;

    //Find Perticular Word inside string
    s = "I am Learning string Update";           //Update s String
    cout << s << endl;

    string word = "Learning";
    int index = s.find(word);
    cout << "word is present at: " << index << endl;

    //to Delete/Erase the word;
    s.erase(index, word.length() + 1);      //+1 is for remove the extra space after word
    cout << s << endl; 

    return 0;
}
