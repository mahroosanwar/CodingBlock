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