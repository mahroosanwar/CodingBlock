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