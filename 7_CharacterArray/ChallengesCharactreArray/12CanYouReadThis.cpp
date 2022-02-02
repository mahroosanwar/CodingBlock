//Can You Read This

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char a[1000];
    cin.getline(a,1000);
    for(int i = 0; a[i] != '\0'; i++){
        cout << a[i];
        if(a[i+1]>=65 && a[i+1]<=90){               
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}