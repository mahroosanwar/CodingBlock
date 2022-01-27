// Found the key using staircase search

#include <iostream>
using namespace std;

void StairCase(int a[][4], int n, int m, int key){
    int i = 0, j = m-1;
    bool isKeyPresent = false;
    while(i<n & j>=0){
        if(a[i][j] < key){
            i++;
        }
        else if(a[i][j] > key){
            j--;
        }
        else{
            cout << "Key is Found at index " << i << "," << j << endl;
            isKeyPresent = true;
            break;
        }
    }
    if(isKeyPresent == false){
        cout << "Key is not Found";
    }
}

int main(){
    int a[4][4] = {
        {1,4,8,10},
        {2,5,9,15},
        {6,13,18,20},
        {11,14,21,25}
    };
    int key;
    cin >> key;
    
    int n = 4, m = 4;

    StairCase(a,n,m,key);

    cout << endl;
    return 0;
}