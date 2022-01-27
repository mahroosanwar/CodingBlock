//Break for infite loop
//print no 1 to N 
#include <iostream>
using namespace std;

int main()
{
   int i = 1 ,N;
   cout << "Enter the Valuye of N: ";
   cin >> N;
   while (i >= 1)
   {
       cout << i << " " ;
       if (i >= N)
       {
           break;
       }
         i  = i + 1;

   }
   return 0;
   
}