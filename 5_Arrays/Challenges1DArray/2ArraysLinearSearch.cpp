// Arrays Linear Search

#include <iostream>
using namespace std;

void LinearSearch(long long int a[], int n, long long int M){
    for(int i=0; i<=n; i++){        // i<=n beacuse when i==n m not found it 
        if(a[i]==M){                // returns -1
            cout << i;
            break;
        }
        if(i==n)
            cout << -1;
        
    }
}

int main(){
    long long int a[1000];
    int n;
    cin >>n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    int M;
    cin >> M;

    LinearSearch(a,n,M);

    cout << endl;
    return 0;
}