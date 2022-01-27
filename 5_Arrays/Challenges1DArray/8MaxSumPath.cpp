#include <iostream>
using namespace std;

int max(int a, int b){              // Gives maximum
    return(a>b) ? a:b;
}

int MaxSumPath(int a1[], int a2[], int n, int m){
    int sum1 = 0, sum2 = 0, result = 0;

    int i = 0, j = 0;
    while(i<n && j<m){
        if(a1[i] < a2[j])       // if a1[i] < a2[j] then update sum1 with sum + a1[i] then i++;
            sum1 += a1[i++];    //a[i++] => first put i then update

        else if(a1[i] > a2[j])  // if a1[i] > a2[j] then update sum1 with sum + a2[j] then j++;
            sum2 += a2[j++];

        else{
            result += max(sum1, sum2) + a1[i];      //store the max sum in result and add common element
            sum1 = 0;
            sum2 = 0;
                i++;
                j++;

        }
    }
    
    // After no common element remains and either 
    // one of them (i or j)  reach at max so for remaining elements of another arrays=>
    while(i<n){                 
        sum1 += a1[i++];
    }

    while(j<m){
        sum2 += a2[j++];
    }

    result += max(sum1, sum2);
    return result;
}

int main (){
    
    int t;                 //Number of Testcase
    cin >> t;
    int n,m;
    for(int i=0; i<t; i++){
        cin >> n;          //Size of Array 1
        cin >> m;          //Size if array 2
    }
    int a1[n], a2[m];
    for(int i=0; i<n; i++){
        cin >> a1[i];
    }
    cout << endl;
    for(int i=0; i<m; i++){
        cin >> a2[i];
    }

    cout << MaxSumPath(a1, a2, n, m);
    return 0;
}