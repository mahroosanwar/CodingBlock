// Introduction to Arrays (optional)

#include <iostream>
using namespace std;

int main(){
    int a[] = {1,2,3,4,5},n;
    
        cout << "Enter the Value of n: " ;
        cin >> n;
        for (int i= 0; i<n ; i++){
            cin >> a[i];
        }

        for (int i = 0; i<n ;i++)
        {
            cout << a[i]<< " ";
        }
    
}
