//understand Pass by references

#include <iostream>
using namespace std;        

void update(int *a){    //&x is pass into a and   
    *a = *a + 1;        //*a become x
    cout << "inside Function: "<< *a;
}
int main(){
    int x = 10;
    update(&x);
    cout << endl;
    cout << "Inside main: "<< x;
}
