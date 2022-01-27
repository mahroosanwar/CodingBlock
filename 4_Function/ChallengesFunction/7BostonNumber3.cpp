#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int sod=0;
    int temp=N;
    while(temp)
    {
        sod+=temp%10;
        temp/=10;
    }
    for(int i=2;i*i<=N;i++)
        if(N%i==0)
        {
            int count=0;
            while(N%i==0)
            {
                N/=i;
                count++;
            }
            int sum=0;
            int temp=i;
            while(temp)
            {
                sum+=temp%10;
                temp/=10;
            }
            sod-=sum*count;
        }
    if(N!=1)
    {
        int sum=0;
            int temp=N;
            while(temp)
            {
                sum+=temp%10;
                temp/=10;
            }
        sod-=sum;
    }
    //cout<<sod<<" ";
    cout<<(sod==0);
}