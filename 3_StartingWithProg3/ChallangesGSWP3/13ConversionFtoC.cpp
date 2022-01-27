// Conversion (Fahrenheit to Celsius)

#include <iostream>
using namespace std;

int main()
{
    float minF, maxF, step , F;
    cin >> minF >> maxF >> step;
    for (F=minF; F<=maxF; F = F+step)
    {
        int C = (5.0/9)*(F-32);
        cout << F << " " << C << endl;
    }
    return 0;
}

