//Help rahul to search

#include <bits/stdc++.h>
using namespace std;
int rahul__key(int A[], int n, int key){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(A[mid]==key){
            return mid ;
            break;
        }
        else if(A[s]<=A[mid]){
           //2 cases 
            if(A[s]<=key && A[mid]>=key){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }else{
            if(A[mid]<=key && key<=A[e]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    return -1;
}
int main() {

    int n;
    cin>>n;

    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int key;
    cin>>key;

    cout<<rahul__key(A,n,key);
    return 0;
}