//Pattern Magic
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    // Upper HALF
    for(int i=0;i<n;i++){
        // first print n-i stars
        for(int j=0;j<n-i;j++)
            cout<<"*";

        // Print 2*i-1 spaces
        for(int j=0;j<(2*i-1);j++)
            cout<<" ";

        // Again Print n-i stars 
        // but there is one less star in first row
        int no_of_stars = n-i;
        if(i==0)
            no_of_stars--;

        for(int j=0;j<no_of_stars;j++)
            cout<<"*";

        cout<<endl;
    }

    
    // Lower HALF
    for(int i=n-2;i>=0;i--){
        // first print n-i stars
        for(int j=0;j<n-i;j++)
            cout<<"*";

        // Print 2*i-1 spaces
        for(int j=0;j<(2*i-1);j++)
            cout<<" ";

        // Again Print n-i stars 
        // but there is one less star in first row
        int no_of_stars = n-i;
        if(i==0)
            no_of_stars--;

        for(int j=0;j<no_of_stars;j++)
            cout<<"*";

        cout<<endl;
    }
    return 0;
}
