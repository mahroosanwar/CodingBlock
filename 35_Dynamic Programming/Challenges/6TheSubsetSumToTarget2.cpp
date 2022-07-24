//6: The Subset Sum To Target

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool dp[1000][100005]; // use global bcoz large memory can be derived from heap only

bool subset(ll a[], ll n, ll key){

    dp[0][0] = true;
    
    for (int i = 1; i < n+1; i++) {
        dp[i][0] = true;
    }
    for (int j = 1; j < key+1; j++) {
        dp[0][j] = false;
    }

    for(int i=1;i<=n;i++){//<=n
        for(int j=0;j<=key;j++){
            if(j<a[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i]];
        }
    }

    return dp[n][key];
}

int main(){
	ll N, T;
	cin >> N >> T;
	ll arr[N];
	for(ll i = 0; i < N; i++)
		cin >> arr[i];
	
	bool ans = subset(arr, N, T);

	if(ans)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}

