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


// You are at a casino. There are N stacked cards on pile . Each card has a number written on it. Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and check whether the number written on the card is divisible by the ith prime number. If the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai. After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .

// Input Format
// First line contains N and Q. The next line contains N space separated integers representing the initial pile of cards i.e., A0. The leftmost value represents the bottom plate of the pile.

// Constraints
// N < 10^5
// Q < 10^5
// |Ai| < 10^9

// Output Format
// Output N lines, each line containing the number written on the card.

// Sample Input
// 5 1
// 3 4 7 6 5
// Sample Output
// 4
// 6
// 3
// 7
// 5
// Explanation
// Initially:

// A0 = [3, 4, 7, 6, 5]<-TOP

// After 1st iteration:

// A0 = []<-TOP

// A1 = [5, 7, 3]<-TOP

// B1 = [6, 4]<-TOP

// Now first print B1 from top to bottom then A1 from top to bottom.
