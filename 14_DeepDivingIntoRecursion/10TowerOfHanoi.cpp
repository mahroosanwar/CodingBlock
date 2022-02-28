//Tower of  hanoi

#include <bits/stdc++.h>
using namespace std;

void TowerofHanoi(int n, char src, char helper, char dest){
    //base case
    if(n==0){           //when no dist 
        return;
    }

    //rec case

    //1--> n-1 disc from src to helper
    TowerofHanoi(n-1, src, dest, helper);

    cout << "Move " << n << "th Disc " << src << " to " << dest << endl;

    //2--> disc from helper to destination

    TowerofHanoi(n-1, helper, src, dest);

}

int main(){
    int n;
    cin >> n;

    TowerofHanoi(n, 'A', 'B', 'C');

    return 0;
}
