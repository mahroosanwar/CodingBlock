#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cin>>n;

    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;

        int temp[n];
        for(int i=0;i<n;i++){
            temp[i] = v[i];
        }

        for(int i=0;i<n;i++){
            temp[i] = v[i] + v[(i-x+n)%n];     //v[(i-x+n)%n] for circular sum
        }
        
        for(int i=0;i<n;i++){
            v[i] = temp[i];
        }
    }

    long long int ans = 0;
    for(int i=0;i<n;i++){
        ans = (ans + v[i])%1000000007;
    }
    cout<<ans<<endl;
}
