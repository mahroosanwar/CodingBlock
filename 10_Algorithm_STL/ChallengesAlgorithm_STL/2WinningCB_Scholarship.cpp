//Winning CB scholarship

#include<bits/stdc++.h>
using namespace std;

long long int students(long long int N, long long int M, long long int X, long long int Y){
	long long int s = 0;
	long long int e = N;
	long long int ans;
	while(s <= e){
		long long int mid = s+(e-s)/2;
		// if(mid <= (M + Y*(N-mid))) 
        if(mid*X <= (M + Y*(N-mid)))
		{
			ans = mid;
			s = mid+1;
		}
		else
		e = mid-1;
	}
	return ans;
}

int main() {
	long long int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	cout << students(N, M, X, Y); //N- no. of students, M- no. of coupons, X- discount, Y- payment
	return 0;
}
