//Subset sum easy method 2


#include <bits/stdc++.h>
using namespace std;

bool subsetSumEasy(const vector<int> &v, int i = 0, int sum = 0, bool included = false)
{
    if (i == v.size())
    {
        return (sum == 0 && included);
    }

    bool inc = subsetSumEasy(v, i + 1, sum + v[i], true);
    bool exc = subsetSumEasy(v, i + 1, sum, included);

    return inc || exc;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (subsetSumEasy(v))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}


// At each step during the recursion ,
// we make a call once where we include the current element into our sum 
//and another where we exclude. If at the end when we reach the end of the array ,
// we have obtained the sum=0, we return true , else false. 
//During the intermediate recursive calls , we check the result from both the recursive calls ,
// one including the current element and one excluding and return their OR 
//since even if one of them had the subset sum 0 then we have to return true.
// Note that the NULL subset ( subset with no elements ) is not to be 
//considered as that would always have sum 0. To avoid considering that , 
//we take a flag variable bool included = false and mark it as true even 
//if we include a single element. Else it remains false. 
//The NULL subset would be the only subset where the flag would remain false.
// For all other subsets , they would have included at least one element and hence 
//their flag would be true.