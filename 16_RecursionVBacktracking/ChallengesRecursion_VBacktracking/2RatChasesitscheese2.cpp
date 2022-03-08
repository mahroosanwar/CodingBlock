//Rat chase it's cheese  Method 2

#include<bits/stdc++.h>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[10][10],int i,int j,int n,int m,bool &ans){
    if(i==n&&j==m){
        soln[n][m]=1;
        ans = true;

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }        

        return true;
    }
    
    if(i>n||j>m||i<0||j<0){
        return false;
    }
    
    if(maze[i][j]=='X'){
        return false;
    }
    
    bool right,down,up,left;
    soln[i][j] = 1;
    
    if(soln[i+1][j]==0){
        down = ratInMaze(maze,soln,i+1,j,n,m,ans);
    }
    if(soln[i][j+1]==0){
        right = ratInMaze(maze,soln,i,j+1,n,m,ans);
    }
    if(soln[i-1][j]==0){
        up = ratInMaze(maze,soln,i-1,j,n,m,ans);
    }
    if(soln[i][j-1]==0){
        left = ratInMaze(maze,soln,i,j-1,n,m,ans);
    }
    
    if(right||down||left||up){
        return true;
    }
    
    soln[i][j] = 0;
    
    return false;
}


int main() {
    int n,m;
    cin>>n>>m;
    
    char maze[10][10];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    
    int soln[10][10]={0};
    
    bool ans = false;
    ratInMaze(maze,soln,0,0,n-1,m-1,ans);
    
    if(ans==false){
        cout<<"NO PATH FOUND";
    }
    
	return 0;
}