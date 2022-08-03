//Dequeue efficient queue using stack

#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n;
	cin>>n;
	stack<int> s1,s2;
	for(int i=0;i<n;i++){
		s1.push(i);
	}
	while(!s1.empty()){
		while(s1.size() > 1){
			s2.push(s1.top());
			s1.pop();
		}
		cout<<s1.top()<<" ";
		s1.pop();

		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}
	return 0;
}


// Implement a Queue using two stacks Make it Dequeue efficient.

// Input Format
// Enter the size of the queue N add 0 - N-1 numbers in the queue

// Constraints
// Output Format
// Display the numbers in the order they are dequeued and in a space separated manner

// Sample Input
// 5
// Sample Output
// 0 1 2 3 4
