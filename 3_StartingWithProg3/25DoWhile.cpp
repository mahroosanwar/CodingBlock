//Do While condition

#include <iostream>
using namespace std;

int main()
{
    int i=1;                 //Initialization
    do {
        cout << i << endl;     // Task : take a step
        i=i+1;
    }while (i<5);               //condition
    cout << endl;

     i =1; 
    while(i<5)                  //condition
    {
        cout << i << endl;          //task 
        i++;
    }
    cout << endl;
    cout << endl;
    //////////////////////////////////////////////////

    int a=5;
    do{
        cout << a << endl;
        a++;
    }while(a<5);

    cout << endl;

    a =5;
    while (a<5)
    {
        cout << a  << endl;
        a++;
    }
    return 0;
}