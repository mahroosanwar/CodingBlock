// Kartik Bhaiya And The Celebrity Problem

#include<iostream>
#include<stack>
using namespace std;

bool knows(int people[][10], int a, int b){
    return people[a][b];
}

int findCelebrity(int people[][10], int n){

    stack<int> s;

    for(int i=0; i<n; i++){
        s.push(i);
    }

    while(s.size()>1){
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        
        knows(people, A, B) ? s.push(B) : s.push(A);
    }

    if(s.empty()){
        return -1;
    }

    int C = s.top();
    s.pop();

    for(int i=0; i<n; i++){

        if( (i != C)  && (knows(people, C, i) || !knows(people, i, C)) ){
            return -1;
        }
    }

    return C;
}

int main(){
    int N;
    cin >> N;
    int people[N][10];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> people[i][j];
        }
    }

    int celebrity = findCelebrity(people, N);

    if(celebrity == -1){
        cout << "No Celebrity";
    }
    else{
        cout << celebrity;
    }
    return 0;
}


// Kartik Bhaiya, mentor at Coding Blocks, organized a party for their interns at Coding Blocks. In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, she/he doesn’t know anyone in the party. We can only ask questions like “does A know B? “.
// Find the stranger (celebrity) in minimum number of questions.

// Input Format
// First line contains N, number of persons in party. Next line contains the matrix of N x N which represents A knows B when it's value is one.

// Constraints
// None

// Output Format
// Print the celebrity ID which is between 0 and N-1. If celebrity is not present then print "No Celebrity".

// Sample Input
// 4
// 0 0 1 0
// 0 0 1 0
// 0 0 0 0
// 0 0 1 0
// Sample Output
// 2
// Explanation
// In the given case there are 4 persons in the party let them as A, B, C, D. The matrix represents A knows B when it's value is one. From the matrix, A knows C, B knows C and D knows C. Thus C is the celebrity who doesnot know anyone and it's ID is 2. Hence output is 2.

// Code Editor
