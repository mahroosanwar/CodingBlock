//Max Circular sum of SubArray 
//Not Work for All Negative Numbers

#include<bits/stdc++.h>

using namespace std;
// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int a[], int n);

// The function returns maximum circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
// Case 1: get the maximum sum using standard kadane's algorithm
int max_kadane = kadane(a, n);

// Case 2: Now find the maximum sum that includes
// corner elements.
int max_wrap = 0, i;
for (i=0; i<n; i++)
{
        max_wrap += a[i];     // Calculate array-sum
        a[i] = -a[i];       // invert the array (change sign)
}

// max sum with corner elements will be:
// array-sum - (-max subarray sum of inverted array)
max_wrap = max_wrap + kadane(a, n);

// The maximum circular sum will be maximum of two sums
return (max_wrap > max_kadane)? max_wrap: max_kadane;
}

// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int a[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

/* Driver program to test maxCircularSum() */
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
       int n;
       cin>>n;
       int a[n];
       for(int j=0;j<n;j++)
       {
           cin>>a[j];
       }
        cout<< maxCircularSum(a, n) <<endl;
    }
    return 0;
}




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