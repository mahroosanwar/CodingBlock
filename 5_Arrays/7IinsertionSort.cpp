//insertion sort : make number in increasing order

#include <iostream>
using namespace std;

int main(){
    int a[100];
    int n,i,j;
    cin >> n;
    for (i=0; i<n; i++){
        cin >> a[i];
    }
    cout << "Before insertion: ";
    for(i = 0; i<n; i++){
        cout << a[i]<< " ";
    }
    cout<< endl;
    
    for(i = 1; i<n; i++){
        int pickedUpCard = a[i];
        for(j = i-1; j>=0 and a[j]>pickedUpCard; j--){
            a[j+1] = a[j];
        }
        a[j+1] = pickedUpCard;
    }

    for (i = 0; i<n; i++){
        cout << a[i]<< " ";
    }
    cout << endl;
    return 0;
}