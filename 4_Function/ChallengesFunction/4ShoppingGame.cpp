//Shopping Games Whgo Wins

#include <iostream>
using namespace std;

void ShoppingGame(int M, int N){
    int i, j, sum1 = 0, sum2 = 0;

    for(i = 1; sum1<=M; i = i+2){
        sum1 = sum1 + i;
    }
    for(j = 2; sum2<=N; j = j+2 ){
        sum2 = sum2 + j;
    }
    if(i>j){
        cout <<  "Aayush" << endl;
    }
    else{
        cout << "Harshit" << endl;
    }
}

int main(){
    int T,M,N;
    cin >> T;

    for(int i = 0; i<T; i++)
    {   
        cin >> M >> N;
        ShoppingGame(M, N);
    }
    return 0;
}