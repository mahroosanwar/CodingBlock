//Input White Character ' ', '\n', '\t'

#include <iostream>
using namespace std;

int main()
{   int count = 0;
    char ch;
    // cin >> ch;
    ch = cin.get(); // To read the white space
    while (ch!='$')
    {
        count++;
        ch = cin.get();
    }
    cout << "Total number of character "<< count << endl;
    cout<< endl;
    return 0; 
}