//Increasing Decreasing Numbers

#include <iostream>
using namespace std;


//first print the numb. then we move up (or call recurrence relation) in stack flow diagram 
void PrintDecr(int n){
    if(n==0){
        return;
    }
    cout << n << " ";
    PrintDecr(n-1);

}

//while coming downwardsfrom stack flow diagram it will print the numbers 
void PrintIncr(int n){
    if(n==0){
        return;
    }
    PrintIncr(n-1);
    cout << n << " ";

}

int main(){
    int n;
    cin >> n;
    cout << "Decreasing Number: " << endl;
    PrintDecr(n);

    cout << '\n' << "Increasing Number: " << endl;
    PrintIncr(n);

    return 0;
}