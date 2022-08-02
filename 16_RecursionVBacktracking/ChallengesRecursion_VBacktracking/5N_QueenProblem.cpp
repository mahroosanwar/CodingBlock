//  N_Queen Problem

#include <iostream>
using namespace std;

//helper function --> to check is it safe to place the Queen in the board in the cell i, j
bool canPlace(int n, int i, int j, int board[][100]){
    //check for colm
    for(int row=0; row<i; row++){
        if(board[row][j] == 1){
            return false;
        }
    }

    //check for left diagonal
    int x = i, y = j;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    } 

    //check for right diagonal
    x = i, y = j;
    while(x>=0 && j<n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }

    //so position is safe now 
    return  true; 
}
int cnt=0;
void NQueen(int n, int i, int board[][100]){
    //base case
    if(i == n){
        //successfully placed all Queens
        //print ans

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){
                    cout << '{' << i+1 << '-' << j+1 << '}' << " ";
                }
            }
        }
        cout << " ";
        cnt++;  //to count the total possible way
        return;
    }
    //recursive case

    //try to place the queen in current row and call on the remaining part 
    //which will solved by recursion

    for(int j=0; j<n; j++){
        //check if i and jth position ssafe or not for the queen
        if(canPlace(n, i, j, board)){
            //Place the Queen -- Assuming that i, j  is the right position 
            board[i][j] = 1;        //means we placed the queen in here

            NQueen(n, i+1, board);

            //if isNextQueenValid id false so we try for next position using loop
            //means i, j is not the right position (i.e. assumption is wrong)

            // backtring for right position
            board[i][j] = 0;        //so we correct our assumption
        }
    }
    //you have tried all position in the current row but couldn't place queen5
    return;
}

int main(){
    int n;
    cin >> n;
    int board[100][100] = {0};
    NQueen(n, 0, board);
    cout << endl << cnt;

    return 0;
}

// Take as input N, the size of a chess board. We are asked to place N number of queens in it, so that no queen can kill other.

// a. Write a recursive function which returns the count of different distinct ways the queens can be placed across the board. Print the value returned.

// b. Write a recursive function which prints all valid configurations (void is the return type for function).

// Input Format
// Enter the number N(Size of the chessboard)

// Constraints
// None

// Output Format
// Display the number of possible ways of arranging N queens and print all the possible arrangements in a space separated manner

// Sample Input
// 4
// Sample Output
// {1-2} {2-4} {3-1} {4-3}  {1-3} {2-1} {3-4} {4-2}
// 2
