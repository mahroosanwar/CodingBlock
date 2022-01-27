//Method 2 without function

#include<iostream>
using namespace std;

int main() {
	long long int T;
	cin>>T;

	long long int k=1;
    while(k<=T)
	{
		long long int m;
	    long long int n;
	    cin>>m;
		cin>>n;
		long long int i = 1;
	    long long int j = 2;

        m -= i;
        n -= j;

        while(true){

            if(m<0){
                cout<<"Harshit"<<endl;
                break;
            }

            if(n<0){
                cout<<"Aayush"<<endl;
                break;
            }

            i += 2;
            j += 2;
            m -= i;
            n -= j;
        }
        k++;
	}

	return 0;
}