//Unique Numbers - II

#include <iostream>
using namespace std;

bool compare(int a, int b){
    return a<b;
}
void UniqueNumbers_II(int a[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= a[i];
    }
    int result = ans;
    //1: extrect the bit pos with value 1, that means it would be diff. in both unique numbers
    int pos = 0;
    while(ans>0){
        if((ans&1) == 1){
            break;
        }
        ans >>= 1;
        pos++;
    }
    //2: we need to separate according to bit position

    int x = 1 << pos;
    int un1 = 0;
    for(int i=0; i<n; i++){
        if((a[i]&x) == 0){
            un1 ^= a[i];
        }
    }
    int un2 = result^un1;
    
    //in increasing order
    if(compare(un1,un2)){
        cout << un1 << " " << un2;
    }
    else{
        swap(un1,un2);
        cout << un1 << " " << un2;
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    UniqueNumbers_II(a,n);
}


// We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

// Input Format
// First line contains the number n. Second line contains n space separated number.

// Constraints
// n < 10^5

// Output Format
// Output a single line containing the unique numbers separated by space

// Sample Input
// 4
// 3 1 2 1
// Sample Output
// 2 3
// Explanation
// Smaller number comes before larger number
