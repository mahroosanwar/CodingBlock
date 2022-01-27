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
