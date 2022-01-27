//Find The pair that will equal to given sum
//Two pointer approach

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[] = {1,4,6,5,8,10};
    int n  = sizeof(a) / sizeof (int);
    int i = 0,j = n-1;
    int sum = 11;
    sort(a,a+n);
    while (i<j){                            //if i=j so it represent same bucket
        if(a[i]+a[j] == sum){
            cout << a[i] << " " << a[j]<<endl;
            i++;
            j--;
        }
        else if(a[i]+a[j] < sum){
            i++;
        }
        else if(a[i]+a[j] > sum){
            j--;
        }
    }
    return 0;   
}