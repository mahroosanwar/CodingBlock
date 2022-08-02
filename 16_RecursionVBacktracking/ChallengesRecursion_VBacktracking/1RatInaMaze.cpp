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


// You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from position (i,j), down or right on the grid.
// Initially rat is on the position (1,1). It wants to reach position (N,M). Find the rightmost path through which, rat can reach this position. A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1), if there exists a path from (i,j+1) to (N,M).

// Input Format
// First line contains 2 integers, N and M, denoting the rows and columns in the grid. Next N line contains. M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

// Constraints
// 1<=N,M<=1000 GRID(i,j)='X' or 'O'

// Output Format
// If a solution exists: Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
// If solution doesn't exist, just print "-1".

// Sample Input
// 5 4
// OXOO
// OOOX
// OOXO
// XOOO
// XXOO
// Sample Output
// 1 0 0 0 
// 1 1 0 0 
// 0 1 0 0 
// 0 1 1 1 
// 0 0 0 1 
