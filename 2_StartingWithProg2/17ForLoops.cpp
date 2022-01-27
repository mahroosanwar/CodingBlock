//write even no using For loops

#include <iostream>
using namespace std;

int main()
{
    int i ,N;
    cout << "Enter the number ";
    cin >> N;
    for (i=2; i<=N; i=i+2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}