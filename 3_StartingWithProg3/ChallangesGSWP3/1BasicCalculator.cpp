//Basic Calculator

#include <iostream>
using namespace std;

int main()
{
    int N1, N2;
    char ch;
    do
    {
        cin >> ch;
            switch(ch)
            {
                case '+':
                    cin >> N1 >> N2;
                    cout << N1 + N2 << endl;
                    break;

                case '-':
                    cin >> N1 >> N2;
                    cout << N1-N2 <<endl;
                    break;
        
                case '*':
                    cin >> N1 >> N2;
                    cout << N1*N2 << endl;
                    break;
        
                case '/':
                    cin >> N1 >> N2;
                    cout << N1/N2 << endl;
                    break;

                case '%':
                    cin >> N1 >> N2;
                    cout << N1%N2 << endl;
                    break;
                
                case 'x':
                case 'X':
                        break;
                default :
                    cout <<"Invalid operation. Try again." << endl;        
            }
            if(ch=='x' || ch=='X'){
                break;
            }
    }while(1);
    
    cout << endl;
    return 0;
}

// Write a program that works as a simple calculator.

// 1.It reads a character (ch)
// 2.If ch is among '+', '-', '*', '/' or '%' it furthur takes two numbers (N1 and N2 as input). It then performs appropriate appropriate operation between numbers and print the number.
// 3.If ch is 'X' or 'x', the program terminates.
// 4.If ch is any other character, the program should print 'Invalid operation. Try again.' and seek inputs again (starting from character).


// Write code to achieve above functionality.

// Input Format
// Constraints
// 0 <= Input integers <= 100000000
// ( It is assured that the second integer provided for division and modulo operations will not be 0. )

// Output Format
// Output a single integer output for the operations in a new line each.

// Sample Input
// * 
// 1 
// 2 
// / 
// 4 
// 2 
// + 
// 3 
// 2 
// ; 
// X
// Sample Output
// 2 
// 2 
// 5 
// Invalid operation. Try again.
// Explanation
// Maybe use a do-while.
