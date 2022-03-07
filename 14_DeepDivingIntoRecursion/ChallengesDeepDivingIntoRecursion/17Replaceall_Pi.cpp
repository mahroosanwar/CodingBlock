// Replace all pi

#include <iostream>
using namespace std;

void Replaceallpi(char *a, int i){
    //base case
    if(a[i] == '\0'){
        cout << a << endl;
        return;
    }

    //recursive case
    if(a[i] == 'p' && a[i+1] == 'i'){
        //start j after 'p', 'i' character
        int j = i + 2;

        while(a[j] != '\0') j++;    //increase j to the end of string

        while(j >= i+2){
            a[j+2] = a[j];          //shift jth char 2 times in right bcz 3.14 have 4 char. and pi char 2 char
            j--;
        }
        
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';

        Replaceallpi(a, i+4);
    }
    else{
        Replaceallpi(a, i+1);
    }

}
int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i<n; i++){
        char a[1000];
        cin >> a;
        Replaceallpi(a, 0);
    }
}