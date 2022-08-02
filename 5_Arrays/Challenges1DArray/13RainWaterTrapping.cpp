//WAP to find the rain water tapping in the hight of the building (which is size of the array)

#include <iostream>
#include <algorithm>

using namespace std;

void RainWater(int a[], int n){
    int left[n], right[n];
    // left[i] contains height of tallest bar to the 
    // left of i'th bar including itself 

    left[0] = a[0];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], a[i]);     //make current element max of the current and past element
    }
    // Right [i] contains height of tallest bar to 
    // the right of ith bar including itself 

    right[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--){
        right[i] = max(right[i+1], a[i]);       //make current element max of the current and the ahead element
    }
    int totalRain = 0;
    for(int i=0; i<n; i++){
        totalRain += (min(left[i], right[i]) - a[i]);      // take min of above array and subtract a[i]
    }
    cout << totalRain << endl;

}
int main(){
    int t;
    cin >> t;
    int n;
    for(int i=0; i<t; i++){
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        RainWater(a,n);
    }
    cout << endl;
    return 0;
}

// You are given an input array whose each element represents the height of a line towers. The width of every tower is 1. It starts raining. Water is filled between the gap of towers if possible. You need to find how much water filled between these given towers.

// Example : Imgur

// Input Format
// The first line consists of number of test cases T. Each test case consists an integer N as number of towers and next line contains the N space separated integers.

// Constraints
// 1 <= N <= 1000000 1 <= t <= 10 0 <= A[i] <= 10000000

// Output Format
// Print how much unit of water collected among towers for each test case.

// Sample Input
// 2
// 6
// 3  0  0  2  0  4
// 12
// 0  1  0  2  1  0  1  3  2  1  2  1
// Sample Output
// 10
// 6


//Rainwater Trapping Problem | Arrays - 5 | DSA-One Course #16 | Anuj Bhaiya
