// Rat in a maze

#include <iostream>
using namespace std;

bool RatInAMaze(char maze[][1000], int soln[][1000], int i, int j, int n, int m){
    // base case
    if(i == n && j == m){
        soln[n][m] = 1;
        //print soln
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    
    // recursive case
    //Rat should be inside the grid
    if(i>n || j>m) return false;

    //cell is blocked
    if(maze[i][j] == 'X') return  false;

    //Assume the soln exist through current cell
    soln[i][j] = 1;

    bool rightSuccess=RatInAMaze(maze,soln,i,j+1,n,m);
    if(rightSuccess)
        {  
            soln[i][j] = 0;
            return true;
        }

    bool downSuccess=RatInAMaze(maze,soln,i+1,j,n,m);
    if(downSuccess)
        {  
            soln[i][j] = 0;
            return true;
        }

    // backtracking
    soln[i][j] = 0;

    return false;
}

int main(){
    int N, M;
    cin >> N >> M;

    char maze[1000][1000];
    int soln [1000][1000] = {0};
    
    for(int i=0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> maze[i][j];
        }
    }

    bool ans = RatInAMaze(maze ,soln, 0, 0, N-1, M-1);

    if(ans == false) cout << "-1" << endl;

    return 0;
}
