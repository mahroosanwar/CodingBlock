//Last Occurance

#include <iostream>
using namespace std;

//by updating iterator
int LastOccurance(int *a, int n, int i, int key){
    //base case
    if(i == n){
        return -1;
    }
    //recursive case;
    if(a[i] == key){
        //i could be found
        int bi = LastOccurance(a, n, i+1, key); //bi is bigger index
        if(bi != -1){
            return bi;
        }
        else{
            return i;
        }
    }

    //if the element we currenly standing is not equal to key(a[i] != key) so we ask the ans from
    //smaller array 
    return LastOccurance(a, n, i+1, key);
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

    cout << LastOccurance(a,n,0,key);

    return 0;
}
