//  Recursion-Subsequences

#include <iostream>
using namespace std;
int cnt = 0;
void  Rec_Subsequences(char *ip, char *op, int i, int j){
    //base case
    
    if(ip[i] == '\0'){
        cnt++;
        op[j] = '\0';
        cout << op << " ";
        return;
    }

    //recursion case
    //1--> ignore the ith char;  
    Rec_Subsequences(ip, op, i+1, j);

    //2--> take the ith char
    op[j] = ip[i];

    //and increase i and j

    Rec_Subsequences(ip, op, i+1, j+1);

}
int main(){
    char a[100];
    cin >> a;
    char op[100];
    Rec_Subsequences(a, op, 0, 0);
    cout << '\n' << cnt;

}