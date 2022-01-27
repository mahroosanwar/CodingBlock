// Von Neuman Loves Binary

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i<N; i++)
    {
        int no;
        cin >> no;
        int num = 0,place = 0;
        while(no!=0)
        {
            
            int rem = no%10;     //Gives Remainder
            num = num + rem*pow(2,place);
            place++;
            no = no/10;
        }
        cout << num << endl;
    }
    return 0;
}