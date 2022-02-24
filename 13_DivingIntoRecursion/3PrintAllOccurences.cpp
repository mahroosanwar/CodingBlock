// Print All Occurences

#include <iostream>
using namespace std;

//to store the ans in array 
int out[100];
int j = 0;

void PrintAllOccurence(int *a, int n, int i, int key){
    //Base Case
    if(i == n){
        return;
    }

    //recursive case

    if(a[i] == key){
        cout << i << " ";
        out[j] = i;
        j++;
    }
    PrintAllOccurence(a,n,i+1,key);
}

int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int key;
    cin >> key;

    PrintAllOccurence(a,n,0,key);

    cout << '\n' << "Indices are: " << endl;

    for(int i=0; i<j; i++){         //i<j only print indices value not others zero   
        cout << out[i] << " ";
    }
    return 0;
}