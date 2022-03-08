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