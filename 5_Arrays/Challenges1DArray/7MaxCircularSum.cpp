// Max Circular Sum of An array
//But Time Limeted Exceed Time Limited Exceed
//Not Work for all negative numbers

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int MaxSubArraySum(int a[], int n){        //Non-Circular
    
    int max = INT_MIN;
    for(int i = 0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum += a[(k)];
            }
            if(max < sum){
                max = sum;
            }
        }
    }
    return max;
}

int MaxCircularSum(int a[], int n){                 //Circular Sum
    int  Max_SubArraySum = MaxSubArraySum(a,n);

    // Corner Case
    if (n == 1)
        return a[0];

    int max_sum = 0;            
    for(int i=0; i<n; i++){
        max_sum += a[i];            //Calculate Array Sum
        a[i] = -a[i];               //Change sign of Array
    }
    max_sum += MaxSubArraySum(a,n);
    
    return (max_sum, Max_SubArraySum) ? max_sum : Max_SubArraySum; 
}
int main(){
    
    int t;
    cin >> t;

    for(int i=0; i<t; i++){

        int n;
        cin >> n;
        int a[n];

        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        cout << MaxCircularSum(a,n) << endl;
    }

    cout << endl;
    return 0;
}

//Question: 
// You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive numbers.

// Input Format
// First line contains integer t which is number of test case.
// For each test case, it contains an integer n which is the size of array and next line contains n space separated integers denoting the elements of the array.

// Constraints
// 1<=t<=100
// 1<=n<=1000
// |Ai| <= 10000

// Output Format
// Print the maximum circular sum for each testcase in a new line.

// Sample Input
// 1
// 7
// 8 -8 9 -9 10 -11 12
// Sample Output
// 22
// Explanation
// Maximum Circular Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)


//Approach:
// For maximum circular sub array sum you need to consider the maximum of these 2 cases:

// The maxm sum subarray is obtained in non circular fashion as in normal Kadane’s algorithm.
//Apply normal Kadane on the array and obtain this.
// The maxm circular sub array sum is obtained in a circular fashion.
// To compute the 2nd case:
// As you know that Kadane algo gives the maxm subarry sum…
//so if you invert the sign of each element of the array and then apply Kadane,
// the maxm subarray sum now obtained will actually be the minimum subarray sum for the original array.

// Consider array elements as: 1 2 -1 -3 4 6
// 1.maximum subarray sum in non circular fashion is: 4+6=11
// 2. on inverting the signs, the array becomes: -1 -2 1 3 -4 -6
// Now applying Kadane, maxm subarry sum is: 1+3=4
// So minimum subarray sum for the original array is: -4
// 3. Now cumulative sum of the original array is: 1+2-1-3+4+6= 9
// If you subtract the minimum sub array sum from cumulative sum you get: 9-(-4)=13 which is actually the
// maximum subarray sum in circular fashion ie. 4+6+1+2=13 .
// So now the answer will be max(11,13)=13.
