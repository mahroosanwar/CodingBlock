#include <iostream>
using namespace std;

int main()
{
    int p,r,t;
    float SI;
    cout << "Enter Value of P: " << endl;
    cin >> p;
    cout << "Enter Value of R: " << endl;
    cin >> r;
    cout << "Enter Valur of time: " << endl;
    cin >> t;

    SI = (p*r*t)/100; 

    cout << SI;

    return 0;

}
