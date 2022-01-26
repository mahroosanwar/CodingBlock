// Value and Nature of roots of Quadratic Equations

#include <iostream>
#include <cmath>
using namespace std;

int main()
{   int a,b,c,D,x1,x2; 
    cin >> a >> b >> c;

    D = b*b - 4 * a * c;//D is Discriminant
    
    if (D > 0)
    {
        cout << "Real and Distinct" << endl;
        x1 = (-b - sqrt(D))/(2*a);  //x1,x2 are roots;
        x2 = (-b + sqrt(D))/(2*a); 
        cout << x1 << " " << x2;
    }
    else if (D == 0)
    {
        cout << "real and Equal" << endl;
        x1 = -b/(2*a);                  //x1 value of equal root
        cout << x1 << " " << x1 ;
    }
    else
        cout << "imaginary";
    
    return 0;
}