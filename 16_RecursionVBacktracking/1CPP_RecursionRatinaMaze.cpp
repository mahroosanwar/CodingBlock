//CPP - Recursion Rat in a Maze

#include <iostream>
using namespace std;

bool RatinMaze(char maze[10][10],int soln[][10], int i, int j, int m, int n){
    //base case
    if(i == m && j == n){
        soln[m][n] = 1;
        //print maze
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    //recursive case
    //rat should inside the grid
    if(i>m || j>n) return false;

    //if cell is blocked
    if(maze[i][j] == 'X') return false;

    //assume the solution exist through cell
    soln[i][j] = 1;

    bool rightSuccess  = RatinMaze(maze, soln, i, j+1, m, n);
    bool downSuccess = RatinMaze(maze, soln, i+1, j, m, n);

    //backtracking
    soln[i][j] = 0;

    if(rightSuccess || downSuccess) return true;
    
    return false;
}

int main(){
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00",
    };

    int soln[10][10] = {0};
    int m = 4, n = 4;
    
    bool ans = RatinMaze(maze, soln, 0, 0, m-1, n-1);

    if(ans == false){
        cout << "Path doesn't exist!  ";
    }

    return 0;
}
