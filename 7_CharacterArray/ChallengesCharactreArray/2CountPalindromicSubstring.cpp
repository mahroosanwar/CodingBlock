//Count Palindromic Substring

#include <iostream>
#include <cstring>
using namespace std;


//to check palindrome
bool Palindrome(char a[],int i,int j){
    
    while(i<j){
        if(a[i] != a[j]){
            return false;
        }
        i++, j--;
    }
    return true;
}

// to count total palindrome
void CountPalindromicSubstring(char a[]){
    int len = strlen(a);
    int count = 0;
    
    
    for(int i=0;i<len; i++){
        char temp[1000];     
        for(int j=i; j<len; j++){
            temp[j] = a[j];
           
            if(Palindrome(temp,i,j)){
                count++;
            }
        }
    }
    cout << count ;
}
int main(){
    char a[1000];
    cin >> a;

    CountPalindromicSubstring(a);

    cout << endl;
    return 0;
}
