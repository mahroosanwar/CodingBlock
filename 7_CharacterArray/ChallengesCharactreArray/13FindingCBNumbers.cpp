#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long stoint(string s)
{                                
    long i,j=0;
    i = 0;
    while(s[j] >= '0' && s[j] <= '9')
    {
        i = i * 10 + (s[j] - '0');
        j++;
    }
    return i;
}

bool is_cb_number(string s)
{
    long long num = stoint(s);
    if (num == 0 || num == 1) {
        return false;
    }
    int arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
            if (num == arr[i]) {
                return true;
            }
        }

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
            if (num % arr[i] == 0) {
                return false;
            }
        }

    return true;
}

bool is_valid(bool * visited, int l, int r)
{
    for(int i=l;i<r;i++)
    {
        if(visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    long count = 0;
    bool* visited = new bool[n];
  for(int i=0; i<s.length(); i++)
    {
        visited[i]=false;
    }
    for(int i=1; i <= s.length(); i++)
    {
        for(int j=0; j<=s.length()-i; j++)
        {   int e = j+i;
            string sub = s.substr(j, e-j);
            if(is_cb_number(sub) && is_valid(visited,j,e))
            {
                count++;
                for(int k=j;k<e;k++)
                {
                    visited[k]=true;
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}


// Deepak and Gautam are having a discussion on a new type of number that they call Coding Blocks Number or CB Number. They use following criteria to define a CB Number.

// 0 and 1 are not a CB number.
// 2,3,5,7,11,13,17,19,23,29 are CB numbers.
// Any number not divisible by the numbers in point 2( Given above) are also CB numbers.
// Deepak said he loved CB numbers.Hearing it, Gautam throws a challenge to him.

// Gautam will give Deepak a string of digits. Deepak's task is to find the number of CB numbers in the string.

// CB number once detected should not be sub-string or super-string of any other CB number.
// Ex- In 4991, both 499 and 991 are CB numbers but you can choose either 499 or 991, not both.

// Further, the CB number formed can only be a sub-string of the string.
// Ex - In 481, you can not take 41 as CB number because 41 is not a sub-string of 481.

// As there can be multiple solutions, Gautam asks Deepak to find the maximum number of CB numbers that can be formed from the given string.

// Deepak has to take class of Launchpad students. Help him by solving Gautam's challenge.

// Input Format
// First line contain size of the string.

// Next line is A string of digits.

// Constraints
// 1 <= Length of strings of digits <= 17

// Output Format
// Maximum number of CB numbers that can be formed.

// Sample Input
// 5
// 81615
// Sample Output
// 2
// Explanation
// 61 and 5 are two CB numbers.
