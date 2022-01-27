//Print All prine no up to N

#include <iostream>
using namespace std;

int main()
{
    int i,N,no;
    cout << "Enter the Number: " << endl;
    cin >> N;
    for (no = 2; no<=N; no = no + 1)
    {
        for (i = 2; i < no; i++  )
        {
            if (no % i == 0 )
            {
                break;
            }
        } 
        if (i == no)  
        {
            cout << no << " "; // pirnt the no because it's prime
        }
    }
    cout << endl;
    return 0;
}