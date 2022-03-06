//Set Example - Unique Permutations

#include <iostream>
#include <set>
#include <string>
using namespace std;

void UniquePermute(char *in, int i, set <string> &s){
    //base case
    if(in[i] == '\0'){
        // cout << in << endl;
        
        //insted of print in[], -- we make a string t and initialize with array in[]
        //that is the current output and which will show on screen
        string t(in);

        //now push this string object inside the set
        //the string t taht was initially output is not now output it will inside the set
        //that will maintain only unique string

        s.insert(t);
    }

    //recursive case
    for(int j=i; in[j] != '\0'; j++){
        swap(in[i], in[j]);
        UniquePermute(in, i+1, s);
        
        //Backtracking --> to restore the original array
        swap(in[i], in[j]);
    }
}

int main(){
    char in[100];
    cin >> in;
    cout << endl;

    set<string> s;

    UniquePermute(in, 0, s);

    //loop over the set
    //this set only store the unique string
    for(auto str:s){
        cout << str << ", ";
    }
    return 0;
}