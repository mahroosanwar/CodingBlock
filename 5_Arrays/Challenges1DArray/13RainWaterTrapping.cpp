//WAP to find the rain water tapping in the hight of the building (which is size of the array)

#include <iostream>
#include <algorithm>

using namespace std;

void RainWater(int a[], int n){
    int left[n], right[n];
    // left[i] contains height of tallest bar to the 
    // left of i'th bar including itself 

    left[0] = a[0];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], a[i]);     //make current element max of the current and past element
    }
    // Right [i] contains height of tallest bar to 
    // the right of ith bar including itself 

    right[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--){
        right[i] = max(right[i+1], a[i]);       //make current element max of the current and the ahead element
    }
    int totalRain = 0;
    for(int i=0; i<n; i++){
        totalRain += (min(left[i], right[i]) - a[i]);      // take min of above array and subtract a[i]
    }
    cout << totalRain << endl;

}
int main(){
    int t;
    cin >> t;
    int n;
    for(int i=0; i<t; i++){
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        RainWater(a,n);
    }
    cout << endl;
    return 0;
}

//Rainwater Trapping Problem | Arrays - 5 | DSA-One Course #16 | Anuj Bhaiya