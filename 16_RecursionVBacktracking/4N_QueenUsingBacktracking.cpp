//N-Queen Using Backtracking

#include <iostream>
using namespace std;

//helper function --> to checj is it safe to place the Queen in the board in the cell i, j
bool isSafe(int board[][10], int i, int j, int n){
    //check for the column
    for(int row=0; row < i; row++){
        if(board[row][j] == 1){
            return false;
        }
    }
    //check for left diagonal

    int x = i, y = j;  //initial point

    while(x>=0 && y>=0){      //we have to remain inside the board
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    // Check for the right Diagonal
    x = i, y = j;  //initial point

    while(x>=0 && y<n){      //we have to remain inside the board
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;        //increment of column in right diagonal
    }
    
    //Position is now safe col, and Diagonal

    return true;
}
bool solve_N_Queen(int board[][10], int i, int n){        //i --> current rows, n --> no of queens
    //base case
    if(i == n){
        //means successfully placed queens in n rows (0....n-1)
        //print the board
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){
                    cout << "Q ";
                }
                else{
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        cout << endl << endl;
        // return true;  --> it return one configuration bcz it will not check for the next col bcz it have ture

        // if return false; give all configuration bcz it thinks it is false so go for next configuration
        return false;

    }

    // recursive case
    //try to place the queen in current row and call on the remaining part 
    //which will solved by recursion
    
    //iterate all the in the current col
    for(int j=0; j<n; j++){
        //check if i and jth position ssafe or not for the queen
        if(isSafe(board, i, j, n)){
            //Place the Queen -- Assuming that i, j  is the right position 
            board[i][j] = 1;            //means we placed the queen in here

            //we placed the queen and will check for the next queen is valid or not to placed
            //according to previous queen 
            bool isNextQueenValid = solve_N_Queen(board, i+1, n);
            
            if(isNextQueenValid){
                return true;
            }

            //if isNextQueenValid id false so we try for next position using loop
            //means i, j is not the right position (i.e. assumption is wrong)

            //backtrack for right position
            board[i][j] = 0;        //so we correct our assumption
        }
    } 
    //you have tried all position in the current row but couldn't place queen5
    return false;
}

int main(){
    int n;
    cin >> n;

   int board[10][10] = {0};
    solve_N_Queen(board, 0, n);

    return 0;
}