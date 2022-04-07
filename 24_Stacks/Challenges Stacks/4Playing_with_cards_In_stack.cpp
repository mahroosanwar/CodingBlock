//4Playing_with_cards_In_stack 2.cpp

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int q, n, v;
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    for(int i = 5; i <= 10000; i++) //Sieve
    {
        int no = 0;
        for(int j = 2; j*j <= i; j++)
        {
            if(i%j == 0)
                no = 1;
        }
        if(!no)
            primes.push_back(i);
    }
    cin>>n>>q;
    stack<int> st1, st2, st3;
    for(int i = 0 ; i < n; i++)
    {
        cin>>v;
        st1.push(v);
    }
    for(int i = 0 ; i < q; i++)
    {
        if(st1.empty())
            break;
        int cur = primes[i];
        while(!st1.empty())
        {
            int ele = st1.top();
            st1.pop();
            if(ele%cur == 0)
            {
                st2.push(ele);
            }
            else
            {
                st3.push(ele);
            }
        }
        while(!st2.empty())
        {
            cout<<st2.top()<<endl;
            st2.pop();
        }
        st1 = st3;
        while(!st3.empty())
            st3.pop();    
    }
    while(!st1.empty())
    {
        cout<<st1.top()<<endl;
        st1.pop();
    }
    return 0;
}
