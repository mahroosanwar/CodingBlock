#include <iostream>
using namespace std;

int main()
{
    int a = 7,b = 5;

    cout << (a&b)<< endl;  // & operator
    cout << (8&3)<< endl;

    // | OR operator

    cout << (a|b)<< endl;
    cout <<(14|2)<< endl;

    // ^ XOR operator
    cout <<(7^5) << endl;
    cout << (14^1) << endl;
    // << left Shift Operator
    int x=1;
    cout <<"After Left Shift " << (x<<2) << endl;
    cout << "After Left Shift " << (x<<3) << endl;

    // >> Right Shift operator
    int X=8;

    cout << "after Right Shift " << (X>>2) << endl;
    cout << "After Right Shift " << (X>>3) << endl;

    // ~ NOT operator
    cout << "After NOT (~) " << (~a) << endl;
    return 0;
}