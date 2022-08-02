// Mazepath_D(Count, Print)

#include <iostream>
using namespace std;
int cnt = 0;
void  Mazepath_D(int i, int j, int n, int m, string ans){
    //base case
    if(i == n && j == m){
        cout << ans << " ";
        cnt++;
        return;
    }
    //recursive case

    // Vertical CAll

    if(i+1 <= n){
        Mazepath_D(i+1, j, n, m, ans+'V');
    }
    
    //Horizontal call
    if(j+1 <= m){
        Mazepath_D(i, j+1, n, m, ans+'H');
    }
    
    //Digonal call
    if(i+1 <= n && j+1 <= m){
        Mazepath_D(i+1, j+1, n, m, ans+'D');
    }

}
int main(){
    int n, m;
    cin >> n >> m;

    Mazepath_D(0, 0, n-1, m-1, "");
    cout << endl << cnt << endl;
    return 0;
}

// Take as input N1 and N2, both numbers. N1 and N2 is the number of rows and columns on a rectangular board. Our player starts in top-left corner of the board and must reach bottom-right corner. In one move the player can move 1 step horizontally (right) or 1 step vertically (down) or 1 step diagonally (south-east).

// a. Write a recursive function which returns the count of different ways the player can travel across the board. Print the value returned.

// b. Write a recursive function which prints moves for all valid paths across the board (void is the return type for function).

// Input Format
// Enter the number of rows N1 and number of columns N2

// Constraints
// None

// Output Format
// Display the total number of paths and print all the possible paths in a space separated manner

// Sample Input
// 3
// 3
// Sample Output
// VVHH VHVH VHHV VHD VDH HVVH HVHV HVD HHVV HDV DVH DHV DD
// 13
