//Class Assignment

#include<iostream>
using namespace std;
int assign(int num){
	if( num == 1){
	    return 2;
    }
    if( num == 2 ){
        return 3;
    }
    return assign( num - 1)  + assign( num -2);
}
int main() {
	int n;
	cin >> n;
	int num;
	for( int i = 1; i <= n; i++){
		cin >> num;
		cout << "#" << i << " : "<< assign(num) << endl;
	}
	return 0;
}