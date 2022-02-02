// Remove Duplicates 

#include <iostream>
using namespace std;

void RemoveDuplicates(char a[]){
    for(int i=0; a[i] != '\0'; ){
        char ch = a[i];
        int freq = 0;
        while(a[i] == ch){
            freq++;
            if(freq==1){
                cout << ch;
            }
            i++;
        }
    }
}

int main(){
    char a[1000];
    cin >> a;

    RemoveDuplicates(a);

    cout << endl;
    return 0;
}