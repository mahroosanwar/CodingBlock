//Tower of Hanoi

#include <bits/stdc++.h>
using namespace std;

int cnt=0, i=0;
void TOH(int n, string src, string helper, string dest){
    //base case
    if(n == 0){
        return;
        i++;
    }
    //recursive case

    //1--> n-1 disc from src to helper

    TOH(n-1, src, dest, helper);
    if(cnt>=0){
        cout << "Move " << n << "th disc from " << src << " to " << dest << endl;
        cnt++;
    }

    //2--> disc from helper to destination

    TOH(n-1, helper, src, dest);
   
}
int main(){
    int n;
    cin >> n;
    
    //T1 -- > Source, T2 --> Destination, T3 --> Auxillary(helper)
    TOH(n, "T1", "T3", "T2");

    //total no of times recursion call minus total number of times it return (when nbecome zero)
    cout << cnt - i;

    return 0;
}

// Google Tower of Hanoi.

// Using a helper stick (peg), shift all rings from peg A to peg B using peg C. All rings are initally placed in ascending order, smallest being on top.

// No bigger ring can be placed over a smaller ring.

// a. Write a recursive function which prints the steps required to solve the tower of Hanoi problem for N discs.

// b. Write a recursive function which returns number of steps required to solve the tower of Hanoi problem for N discs.

// Let T1 be the Source Tower, T2 be the Destination Tower and T3 be the Auxillary Tower.

// Input Format
// Enter the number of discs

// Constraints
// None

// Output Format
// Display the steps required to solve the tower and also print the total number of steps required

// Sample Input
// 2
// Sample Output
// Move 1th disc from T1 to T3
// Move 2th disc from T1 to T2
// Move 1th disc from T3 to T2
// 3
