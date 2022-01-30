//Compare two string are same or not

#include <iostream>
#include <cstring>

using namespace std;

bool compareStr(char a[], char b[]){
    int i=0, j=0;
    int lena = strlen(a), lenb = strlen(b);

    while(i<lena && j<lenb){
        if(a[i] != b[j]){
            return false;
        }
        i++, j++;
    }
    if(a[i] != '\0' || b[j] != '\0'){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    char a[2000];
    char b[1000];

    cin.getline(a,1000);
    cin.getline(b,1000);

    if(compareStr(a,b) == true){
        cout << "both are Same";
    }
    else{
        cout << "both are not same";
    }

    cout << endl;
    return 0;
}