//Recursion-Pattern_1 (Triangle)

#include <iostream>
#include <string>
using namespace std;

void triangle(int i){
    if(i==0){
        return;
    }
    cout<<"*\t";
    triangle(i-1);
}
void triangle2(int n,int i){
	if(i==n+1){
		return;
	}
	triangle(i);
    cout<<endl;
	triangle2(n,i+1);
}

int main() {
	int n;
	cin>>n;
	triangle2(n,1);
	return 0;
}

// Take as input N, a number. Print the following pattern (for N =4)

// *

// * *

// * * *

// * * * *

// * * * * *

// Input Format
// Enter the value of N

// Constraints
// None

// Output Format
// Tab separated (*)

// Sample Input
// 5
// Sample Output
// *
// *	*
// *	*	*
// *	*	*	*
// *	*	*	*	*
