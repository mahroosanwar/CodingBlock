// Count Frequency

#include <iostream>
using namespace std;

int main(){

    char a[] = "abcbaz";

    int freq[26] = {0};
    // for fill the freq index
    for(int i = 0; a[i] != '\0'; i++){
        char ch = a[i];
        int index = ch -'a';
        freq[index]++;
    }
    
    for(int i = 0; i<26; i++){
        if(freq[i] > 0){
            char  x = i + 'a';              // map char from index
            cout << "Character " << x << "--> "<< freq[i] << endl;
        }
    }
    return 0;
}