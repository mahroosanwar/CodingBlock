//WAP to give the max frequency character

#include <iostream>
#include <cstring>
using namespace std;

void MaxFreqChar(char a[]){
    int freq[26] = {0};

    for(int i=0; a[i] != '\0'; i++){
        freq[a[i]-'a']++;
    }

    int max = 0;
    for(int i=0; i<26; i++){
        if(freq[i] > max){
            max = freq[i];
        }
    }

    for(int i=0; i<26; i++){
        if(freq[i] == max){
            char x = i + 'a';
            cout << x;
        }
    }
}
int main(){
    char a[1000];
    cin >> a;

    MaxFreqChar(a);
    cout << endl;
    return 0;
}
