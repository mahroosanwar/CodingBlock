// 3 Balife

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, arr[1000000], load = 0, max_load = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        load += arr[i];
    }
    if (load % n != 0)
    {
        cout << -1 << endl;
        exit(0);
    }
    int sum = load;
    load = load / n;
    int diff = 0;
    // to calculate left sum
    int cs = 0;
    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        // left transfer
        int lt = abs(cs - load * (i + 1));
        // right transfer
        int rt = abs((sum - cs) - load * (n - i - 1));
        // max of these 2 and prev ans
        max_load = max(max_load, max(lt, rt));
    }
    cout << max_load << endl;
    return 0;
}

// Given an array A of size n, In a single operation you can subtract one from A[i] and add it to either A[i-1] (if i>0) or A[i+1] (if i < n-1).
// Find the minimum number of operation required to make all the array elements same.
// If it is not possible to do , print -1.

// Input Format
// The First line contains the size of the array N The Second line contains the N number of elements

// Constraints
// 0 < N < 100000

// Output Format
// Output Number denoting the minimum number of operations required.

// Sample Input
// 8
// 16 17 15 0 20 1 1 2
// Sample Output
// 23