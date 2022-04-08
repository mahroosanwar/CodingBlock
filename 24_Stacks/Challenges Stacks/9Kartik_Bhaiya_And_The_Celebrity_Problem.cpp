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