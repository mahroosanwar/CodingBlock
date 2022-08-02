#include<iostream>
#include<vector>
using namespace std;

void generateSub(int i,vector<int> v,int n, vector<bool> temp,int sum, int &cntways){
    if(i == n){
        int sumsplit = 0;

        for(int j=0;j<n;j++){
            if(temp[j] == true){
                sumsplit += v[j];
            }
        }
        if(sumsplit == sum){

            for(int j=0;j<n;j++){
                if(temp[j] == true){
                    cout<<v[j]<<" ";
                }
            }
            cout<<"and ";
            for(int x=0;x<n;x++){

                if(temp[x] == false){
                    cout<<v[x]<<" ";
                }
            }
            cout<<endl;
            cntways++;
        }
        return;
    }
    temp[i] = true;
    generateSub(i+1,v,n,temp,sum,cntways);

    temp[i] = false;
    generateSub(i+1,v,n,temp,sum,cntways);
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum += v[i];
    }

    vector<bool> temp(n,false);
    if(sum%2 != 0){
        cout<<"0"<<endl;
        return 0;
    }
    sum = sum/2;
    int cntways = 0;
    generateSub(0,v,n,temp,sum,cntways);
    cout<<cntways<<endl;
}


// Take as input N, a number. Take N more inputs and store that in an array.

// a. Write a recursive function which counts the number of ways the array could be split in two groups, so that the sum of items in both groups is equal. Each number in the array must belong to one of the two groups. Print the value returned.

// b. Write a recursive function which keeps track of ways an array could be split in two groups, so that the sum of items in both groups is equal. Each number in the array must belong to one of the two groups. Return type of function should be void. Print the two groups, each time you find a successful split.

// Input Format
// Take as input N, a number. Take N more inputs and store that in an array.

// Constraints
// None

// Output Format
// Display all the groups in a comma separated manner and display the number of ways the array can be split

// Sample Input
// 6
// 1
// 2
// 3
// 3
// 4
// 5
// Sample Output
// 1 2 3 3 and 4 5 
// 1 3 5 and 2 3 4 
// 1 3 5 and 2 3 4 
// 2 3 4 and 1 3 5 
// 2 3 4 and 1 3 5 
// 4 5 and 1 2 3 3 
// 6
