// Inversion Count
//(count the no. of pairs in an array which have higher value but lower it's position to 
// lower value but higher position)(i.e. a[i] > a[j] for i<j)
 
#include <iostream>
using namespace std;

int merge(int *a, int s, int e){
    
    int mid = (s+e)/2;
    int i = s, j = mid+1, k = s;

    int temp[1000];
    int cnt = 0;        //cross inversion

    while(i<=mid && j<=e){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }

    // remaning elements
    while(i<=mid){
        temp[k++] = a[i++];
    }

    while(j<=e){
        temp[k++] = a[j++];
    }

    for(int i=s; i<=e; i++){
        a[i] = temp[i];
    }

    return cnt;
}

int InversionCount(int *a, int s, int e){
    //base case
    if(s>=e){
        return 0;;
    }

    //recursive case
    //devide the array(as merge sort) and do for it inversion cnt

    int mid = (s+e)/2;
    int x = InversionCount(a, s, mid);
    int y = InversionCount(a, mid+1, e);

    //cnt for the cross inversion

    int z = merge(a, s, e);

    return x+y+z;
}

int main(){
    int a[] = {1, 5, 2, 6, 3, 0};
    int n = sizeof(a)/sizeof(int);

    cout << InversionCount(a, 0, n-1);
    return 0;
}