//Calculate The Sum

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int CyclicArraySum(int a[], int n, int X,int f[]){
    
    
    for (int i = 0; i<n; i++){          

        if ((i-X)<0){                   //for index negative make change it with  
            a[i-X] = a[n-X+i];          //n-X index
            f[i] = a[i] + a[i-X];       //add as given in problem
        }
        else{
            f[i] = a[i] + a[i-X];       //add for all index and store in f[i]
        }
    }
    for(int i = 0; i<n; i++){
        a[i] = f[i];                    //update the a[i] with f[i]
    }
    return f[n];
}

int main(){
    
    int n ;
    cin >> n;

    int a[n], f[n] = {0};     //f is temp array to store

    for(int i = 0; i<n; i++){       // take array input
        cin >> a[i];
    }


    int Q,X;            //no of operation
    cin >> Q;

    for (int i = 0; i<Q; i++){      
        cin >> X;                   
        CyclicArraySum(a,n,X,f);        //for different value of X
    }
    
    for(int i = 0; i<n; i++){       //for Q is zero no value of X
        f[i] = a[i];
    }
    int sum = 0, ans;
    for(int i = 0; i<n; i++){
        sum += f[i];                    //sum in the last
    }
    ans = sum % (1000000007);

    cout << ans;

    cout << endl;
    return 0;
}