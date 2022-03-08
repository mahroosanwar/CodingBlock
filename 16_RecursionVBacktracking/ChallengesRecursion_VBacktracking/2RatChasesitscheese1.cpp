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