//Piyush And Magical Park

#include <iostream>
using namespace std;

void MagicaPark(char a[][100], int n, int m, int k, int s){
    bool success = true;
    for(int i=0; i < n; i++){
        for(int j=0; j<m; j++){
            
            if(s<k){
                success = false;
                break;
            }

            if(a[i][j] == '.'){
                if(j == (m-1)){
                    s-=2;
                }
                else{
                    s-=3;
                }
            }
            else if(a[i][j] == '*'){
                if(j == (m-1)){
                    s+=5;
                }
                else{
                    s+=4;
                }
            }
            else if(a[i][j] == '#'){
                break;
            }
        }
    }
    if(success == true){
        cout << "Yes" << endl;
        cout << s;
    }
    else{
        cout << "No";
    }
}
int main(){
    char a[100][100];
    int N, M, K, S;
    cin >> N >> M >> K >> S;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> a[i][j];
        }
    }
    
    MagicaPark(a,N,M,K,S);
    
    cout << endl;
    return 0;
}