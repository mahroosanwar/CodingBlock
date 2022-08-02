//Print "lowercase" if user enters a character between 'a-z' ,
// Print "UPPERCASE" is character lies between 'A-Z' and 
//print "Invalid" for all other characters like $,.^# etc.

#include <iostream>
using namespace std;

int main()
{
    char x,i,I;
    cin >> x;
    for (i = 'a'; i <= 'z' ; i = i + 1)
    {
        if (x == i)
        {
            cout << "lowercase";
            break;
        }
    }
    for (I = 'A'; I <= 'Z'; I = I + 1)
    {
       if(x == I)
       {
           cout << "UPPERCASE";
           break;
       }
    }
    if (x != i && x != I)
    {
        cout << "Invalid";
    }
    return 0;
}

// Print "lowercase" if user enters a character between 'a-z' , Print "UPPERCASE" is character lies between 'A-Z' and print "Invalid" for all other characters like $,.^# etc.

// Input Format
// Single Character .

// Constraints
// -

// Output Format
// lowercase UPPERCASE Invalid

// Sample Input
// $
// Sample Output
// Invalid
// Explanation
// -
