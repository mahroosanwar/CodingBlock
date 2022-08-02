//CPP - Recursion - Sudoku Solver

#include <iostream>
#include <cmath>
using namespace std;


//help with helper function for no. can be placed or not
bool canPlace(int mat[][100], int i, int j, int n, int number ){

    for(int x=0; x<n; x++){
        //to check row and column
        if(mat[x][j] == number || mat[i][x] == number){
            return false;
        }
    }

    //to check in sub-grid
    int rn = sqrt(n);
    //starting point(index) of sub-grid 
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x = sx; x < sx + rn; x++){
        for(int y = sy; y < sy + rn; y++){
            if(mat[x][y] == number){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][100], int i, int j, int n){
    //base case
    if(i == n){
        //print mat
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    //case for when the row end
    if(j == n){
        return solveSudoku(mat, i+1, 0, n);
    }

    //skip pre-filles cell
    if(mat[i][j] != 0){
        return solveSudoku(mat, i, j+1, n);
    }

    //rec case
    
    //Fill the current cell with possible option(number)
    for(int number = 1; number <=9; number++){
        //help with helper function for no. can be placed or not
        if(canPlace(mat, i, j, n, number)){
            //assume our current no is the answer(may be true or false)
            
            mat[i][j] = number;

            //check are we able to slove sudoku
            bool couldWeSolved = solveSudoku(mat, i, j+1, n);       //check for next cell(colm)

            if(couldWeSolved){      //if sudoku sloved
                return true;
            }
        }
    }
    
    //backtrack here
    mat[i][j] = 0;
    return false;
}

int main(){
    int N;
    cin >> N;
    int mat[100][100];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> mat[i][j];
        }
    }
    solveSudoku(mat, 0, 0, N);

    return 0;
}

// You are given an N*N sudoku grid (N is a multiple of 3). Solve the sudoku and print the solution.
// To learn more about sudoku, go to this link Sudoku-Wikipedia.

// Input Format
// First line contains a single integer N. Next N lines contains N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid. This value is 0, if the cell is empty.

// Constraints
// N=9 Solution exists for input matrix.

// Output Format
// Print N lines containing N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid, such that all cells are filled.

// Sample Input
// 9
// 5 3 0 0 7 0 0 0 0 
// 6 0 0 1 9 5 0 0 0 
// 0 9 8 0 0 0 0 6 0 
// 8 0 0 0 6 0 0 0 3 
// 4 0 0 8 0 3 0 0 1 
// 7 0 0 0 2 0 0 0 6 
// 0 6 0 0 0 0 2 8 0 
// 0 0 0 4 1 9 0 0 5 
// 0 0 0 0 8 0 0 7 9 
// Sample Output
// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9 
