#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll p[1000001]{0};
vector<int> v;
void prime(){
    p[2]=1;
    for(int i=4;i<1000001;i+=2){
        p[i]=0;
    }
    for(int i=3;i<1000001;i+=2){
        p[i]=1;
    }
    for(int i=3;i*i<1000001;i+=2){
        if(p[i]){
            for(int j=i*i;j<1000001;j+=2*i) p[j]=0;
        }
    }
    v.push_back(2);
    for(int i=3;i<1000001;i+=2){
        if(p[i]){
            v.push_back(i);
        }
    }
}

int main() {
    int t;
    cin>>t;
    prime();
    while(t--){
        int  n;
        cin>>n;
        cout<<v[n-1]<<endl;
    }
	return 0;
}