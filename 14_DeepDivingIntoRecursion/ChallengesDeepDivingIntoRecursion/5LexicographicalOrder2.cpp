#include <iostream>
using namespace std;

void LexicographicalCounting(int n, int a) {
    if (a > n) {
        return;
    }
    string str;
    str += to_string(a);
    cout<<str<<" ";
    int i = 0;

    if (a == 0)
        i = 1;

    for (; i <= 9; i++) {
        LexicographicalCounting(n, a * 10 + i);
    }
}

int main() {
    int n;
    cin>>n;
    LexicographicalCounting(n, 0);
}

// To Solve any Problem related to Recursion All you need to do is 
//Break the Problem into 3 important components which are as follows :-

// Bigger Problem : The original Problem statement is your bigger problem.
// Smaller Problem : In every recursive prblm there exist a prblm statement 
//which you need to achieve in order to fullfill the prblm statement but by 
//considering such a smaller prblm from the bigger prblm is needed 
//which we need to assume that the recursion will work and will give the answer.
// Self Work : The amount of work which one should do in order to make the smaller problem your problem.
// For e.g…, In order to find the max of any array, three components will be :-
// Bigger Problem : To find the max in whole array viz find max in array from index 0 to n - 1.
// Smaller Problem : Assume that the recursion works and will find the max of array from index 1 to n - 1.
// Self Problem : In order to make your smaller prblm your bigger prblm 
//all you need to do is to compare the ans return by assuming the smaller 
//prblm works with the 0th index element and return the max among both of them.

// Similarly Classification acc to the Given prblm :-

// Bigger Problem : To Print all of the counting from 1 to N.
// Smaller Problem : Assume the recursion works and will give you ans for 
//counting 2 to N and 3 to N and 4 to N upto 9 to N.
// Self Work : In order to make you smaller prblm your problem all you need to 
//print your current number and rest will be done by the Smaller work.