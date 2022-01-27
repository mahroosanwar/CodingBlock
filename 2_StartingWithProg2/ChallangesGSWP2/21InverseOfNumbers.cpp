#include<iostream>
#include<math.h>
using namespace std;

 int inverse(int num){

    int place = 1;
    int ans = 0;

    while(num != 0){
        int rem = num % 10;
        ans = ans + place * pow(10, rem - 1);
        num = num / 10;
        place++;
    }

    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<inverse(n)<<endl;
    return 0;
}
