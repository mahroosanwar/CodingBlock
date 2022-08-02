//countv Sets Bits

#include <iostream>
using namespace std;

void CountSetBits(int a[], int n){
    for(int i=0; i<n; i++){
        int ans = 0;
        int no = a[i];
        
        while(no > 0){
            if((no&1) == 1){
                ans += 1;
            }
            no >>= 1;
        }
        cout << ans << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    CountSetBits(a,n);
    
    return 0;
}

// count number of 1s in binary representation of an integer

// Input Format
// Input N = Number of Test Cases, followed by N numbers

// Constraints
// Output Format
// Number of Set Bits in each number each in a new line

// Sample Input
// 3
// 5
// 4
// 15
// Sample Output
// 2
// 1
// 4
// Explanation
// Convert Binary to Decimal first and then count number of 1's present in all digits.
