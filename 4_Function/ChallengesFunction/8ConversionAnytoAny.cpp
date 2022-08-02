#include <iostream>
using namespace std;

int conversion(int num, int sb, int db){
    // Any  Base to Decimal
    int ans = 0;
    int mult = 1;
    while(num != 0){
        int rem = num % 10;
        ans  = ans + rem * mult;
        mult = mult * sb;
        num = num / 10;
    }

    // Refresing the variables
    mult = 1;
    num = ans;
    ans = 0;

     //Decimal to Any number
    while(num != 0){
        int rem = num % db;
        ans  = ans + rem * mult;
        mult = mult * 10;
        num = num / db;    
    }  
    return ans;  
}

int main() {
    int sb, db, sn;
    cin>>sb>>db>>sn;
    cout<<conversion(sn, sb,db);
}


// Take sb (source number system base), db (destination number system base) and sn (number in source format). Write a function that converts sn to its counterpart in destination number system. Print the value returned.

// Input Format
// Constraints
// 0 < N <= 1000000000

// Output Format
// Sample Input
// 8
// 2 
// 33
// Sample Output
// 11011
// Explanation
// All input output is as integers and in separate lines.
