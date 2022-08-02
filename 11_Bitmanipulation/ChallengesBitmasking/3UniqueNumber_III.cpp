//Unique Number - III

#include <iostream>
using namespace std;

void UniqueNumber_III(int a[], int n){
    int cnt[64] = {0};

    //make count array by adding all the bits of numb according to the position of the bits
    for(int i=0; i<n; i++){
        int pos = 0;
        int no = a[i];
        while(no>0){
            if((no&1) == 1){
                cnt[pos]++;
            }
            no >>= 1;
            pos++;
        }    
    }

    //Binary to deimal
    int ans = 0, place = 1;

    for(int i=0; i<64; i++){
        cnt[i] %= 3;
    
    //(cnt[] is binary of unique no)

        ans += cnt[i]*place;
        place <<= 1; // equi to  place *= 2; 
    }
    cout << ans << endl;
}

int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    UniqueNumber_III(a, n);

    return 0;
}


// We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once. Find the unique number. Only use - bitwise operators, and no extra space.

// Input Format
// First line contains the number n. Second line contains n space separated number.

// Constraints
// N < 10^5

// Output Format
// Output a single line containing the unique number

// Sample Input
// 7
// 1 1 1 2 2 2 3
// Sample Output
// 3
// Explanation
// 3 is present only once
