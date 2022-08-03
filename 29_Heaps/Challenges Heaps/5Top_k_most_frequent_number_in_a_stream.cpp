// Top k most frequent number in a stream



#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void Ktop(int *arr, int n, int k) {
    vector<int> top(k+1);
    unordered_map<int, int> freq;
    for(int m=0;m<n;m++) {
        freq[arr[m]]++;
        top[k] = arr[m];
        auto it = find(top.begin(), top.end()-1, arr[m]);
        for(int i=distance(top.begin(), it)-1;i>=0;i--) {
            if(freq[top[i]]<freq[top[i+1]]) {
                swap(top[i], top[i+1]);
            } else if(freq[top[i]]==freq[top[i+1]] and top[i]>top[i+1]) {
                swap(top[i], top[i+1]);
            } else {
                break;
            }
        }
        for (int i = 0; i < k && top[i] != 0; ++i) 
            cout << top[i] << ' '; 
    }

    cout<<endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin>>t;
    while(t--) {
      int n, k;
      cin>>n>>k;
      int *arr = new int[n];
      for(int i=0;i<n;i++) {
        cin>>arr[i];
      }
      Ktop(arr, n, k);
      delete [] arr;
    }
    return 0;
}


// Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top (according to their decreasing frequency) every time a new number is read. We basically need to print top k numbers sorted by frequency when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency. If frequency of two numbers are same then print them in increasing order.

// Input Format
// First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n and k, n represents the length of the array and next line contains n space separated integers.

// Constraints
// 1 < t < 100 1< n < 1000

// Output Format
// Print top k running stream.

// Sample Input
// 1
// 5 2
// 5 1 3 5 2
// Sample Output
// 5 1 5 1 3 5 1 5 1
