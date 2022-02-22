//Recursion basics factorical

#include <iostream>
using namespace std;

int fact(int n){
    //1 . Base Case
    if(n==0){
        return 1;
    }

    //2. recurrence relation/Recursive case ; n! = n*(n-1)!
    //fact(n) = n*fact(n-1)

    // int  smallerAns = fact(n-1);

    //3. Find the solution

    // int biggerAns = n*smallerAns;

    // return biggerAns;  

    // or just do this

    return n*fact(n-1);

}

int main(){
    int n;
    cin >> n;

    cout << fact(n);

    return 0;
}
