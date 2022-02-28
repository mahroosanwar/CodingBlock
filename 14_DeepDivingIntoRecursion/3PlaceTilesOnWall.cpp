//Place tiles on a wall

#include <iostream>
using namespace std;

int PlaceTiles(int n){
    //Base case
    if(n<=3)return 1;

    //recursie case

    return PlaceTiles(n-1) + PlaceTiles(n-4);
}
int main(){
    int n;
    cin >> n;

    cout << PlaceTiles(n);

    return 0;
}
