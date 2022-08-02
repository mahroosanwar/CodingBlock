// Duplicate character formatting Method 1

#include <iostream>
using namespace std;

void Formating(char *a, int i){
    //base case
    if(a[i] == '\0'){
        return;
    }

    //recursive cases
    if(a[i] == a[i+1]){
        int j = i+1;
        //shift the jth to end
        while(a[j] != '\0'){
            j++;
        }
        //shift the charactor to 1 position ahead
        while(j>=i+1){
            a[j+1] = a[j];
            j--;
        }
        a[i+1] = '*';
        
        //Now recursion do for smaller string

        Formating(a, i+2);      
    }

    else{

        //ask the recursion to slove the smaller string from i+1
        Formating(a, i+1);
    }
}

int main(){
    char a[1000];
    cin >> a;

    Formating(a, 0);
    cout << a;

    return 0;
}



// Take as input str, a string. Write a recursive function which returns a new string in which all duplicate consecutive characters are separated by a ‘ * ’. E.g. for “hello” return “hel*lo”. Print the value returned

// Input Format
// Enter a String

// Constraints
// 1<= Length of string <= 10^4

// Output Format
// Display the resulting string (i.e after inserting (*) b/w all the duplicate characters)

// Sample Input
// hello
// Sample Output
// hel*lo
// Explanation
// We insert a "*" between the two consecutive 'l' .
