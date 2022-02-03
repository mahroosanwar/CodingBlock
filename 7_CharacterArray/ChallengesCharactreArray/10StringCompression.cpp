//String Compression
#include <iostream>
using namespace std;

void StringCompression(char a[]){
     for(int i=0; a[i] != '\0';){
        char ch = a[i];
        // find freq of ch 
        int freq = 0;
        while(a[i]==ch){
            freq++;
            i++;
        }
        cout<<ch<<freq;
    }
}
   
int main(){
    char a[1000];
    cin >> a;

    StringCompression(a);

    cout << endl;
    return 0;
}