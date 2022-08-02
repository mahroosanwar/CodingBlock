// #include <iostream>
// #include <climits>
// #include<algorithm>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool compare(int a ,int b){
    string num1 = to_string(a);
    string num2 = to_string(b);
    string ab = num1.append(num2);
    string ba = num2.append(num1);
    return ab.compare(ba) > 0 ? true : false;
}
int main()
{
    int t;
    cin >> t; // no. of test cases
    while (t > 0)
    {
        ll int n;
        cin >> n; // no. of elements
        ll int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // logic 
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<endl;
        t--;
    }
    return 0;
}


// You are provided an array of numbers. You need to arrange them in a way that yields the largest value.

// Input Format
// First line contains integer t which is number of test case.
// For each test case, you are given a single integer n in the first line which is the size of array A[] and next line contains n space separated integers denoting the elements of the array A .

// Constraints
// 1<=t<=100

// 1<=m<=100

// 1<=A[i]<=10^5

// Output Format
// Print the largest value.

// Sample Input
// 1
// 4
// 54 546 548 60
// Sample Output
// 6054854654
// Explanation
// Upon rearranging the elements of the array , 6054854654 is the largest possible number that can be generated.
