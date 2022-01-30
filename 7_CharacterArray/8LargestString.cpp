//Largest String

#include <iostream>
#include <cstring>
using namespace std;

void copy(char a[],char b[]){
    int len = strlen(b);
    for(int i=0; i<=len; i++){
        a[i] = b[i];
    }
}
int main(){
    char a[1000];
    char largest[1000];
    int n;
    cin >> n;
    cin.get();
    int largest_len = 0;
    for(int i=0; i<n; i++){
        cin.getline(a,1000);
        int len = strlen(a);
        if(largest_len < len){
            largest_len = len;
            copy(largest, a);
        }
    }
    cout << largest << endl;
    cout << "largest lenght :" << largest_len;

    return 0;
}