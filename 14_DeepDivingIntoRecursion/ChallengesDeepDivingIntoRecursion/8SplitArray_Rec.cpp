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
