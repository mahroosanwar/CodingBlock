#include<iostream>
using namespace std;

bool generate_subset(int* arr,int i,int n,int sum,int count){
	//base case
    if(i == n){
		if(sum==0 &&count>0){
			return true;
		}
		else{ 
			return false;
		}
	}

    //recursive case    
	bool opt1=generate_subset(arr,i+1,n,sum+arr[i],count+1);

	bool opt2=generate_subset(arr,i+1,n,sum,count);
    return opt1 || opt2;
}

int main() {
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int input[n];
		for(int i=0;i<n;i++){
			cin>>input[i];
		}
		if(generate_subset(input,0,n,0,0)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}

	return 0;
}