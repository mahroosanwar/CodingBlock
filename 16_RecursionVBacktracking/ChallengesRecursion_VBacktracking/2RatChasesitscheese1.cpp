// Rat Chase it's Cheese Method 1


#include <iostream>
using namespace std;
bool ratInMaze(char a[100][100], int sol[100][100], int i, int j, int m, int n) {

    if (i == m && j == n) {
        sol[i][j] = 1;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    if (i > m || j > n || i < 0 || j < 0) {
        return false;
    }


    //this is because you stuck in a loop
    // first go left then up and then right then down and so on…
    // you also have to handle this case
    // to handle this case
    // use this condition
    // if(sol[i][j]==1) return false;
    
    if (a[i][j] == 'X' || sol[i][j]) {
        return false;
    }


    sol[i][j] = 1;

    bool rightSuccess = ratInMaze(a, sol, i, j + 1, m, n);
    bool downSuccess = ratInMaze(a, sol, i + 1, j, m, n);
    bool leftSuccess = ratInMaze(a, sol, i, j - 1, m, n);
    bool upSuccess = ratInMaze(a, sol, i - 1, j, m, n);

    if (rightSuccess || downSuccess || leftSuccess || upSuccess) {
        return true;
    }

    sol[i][j] = 0;

    return false;

}

int main()
{
    int n, m;
    cin >> m >> n;

    char a[100][100];
    int sol[100][100] = {0};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bool k = ratInMaze(a, sol, 0, 0, m - 1, n - 1);
    if (k == false)
    {
        cout << "NO PATH FOUND";
    }
    return 0;
}


// You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from a position towards left, right, up or down on the grid.
// Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is waiting for. There exits a unique path in the grid . Find that path and help the rat reach its cheese.

// Input Format
// First line contains 2 integers N and M denoting the rows and columns in the grid.
// Next N line contains M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

// Constraints
// 1 <= N , M <= 10

// Output Format
// Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
// If a path does not exits then print "NO PATH FOUND"

// Sample Input
// 5 4
// OXOO
// OOOX
// XOXO
// XOOX
// XXOO
// Sample Output
// 1 0 0 0 
// 1 1 0 0 
// 0 1 0 0 
// 0 1 1 0 
// 0 0 1 1 
