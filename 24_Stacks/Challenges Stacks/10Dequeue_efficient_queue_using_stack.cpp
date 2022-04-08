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