//key Present or Not

#include <iostream>
using namespace std;
int main()
{
    int a[100] ={1,2 ,12,70};
    int n =4,i;
    int key =12;

    for (i = 0; i<n;i++){
        if(a[i] == key){
            cout <<"Key found at index "<< i;
            break;  //stop the loop
        }
    }

    // two ways to exit loop:
    //when i==n loop gets teminated
    //break statement gets executed
    if(i==n){
        cout << "key not found in index ";
    }
    cout << endl;
    return 0;
}