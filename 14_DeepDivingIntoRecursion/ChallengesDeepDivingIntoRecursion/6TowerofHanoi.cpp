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