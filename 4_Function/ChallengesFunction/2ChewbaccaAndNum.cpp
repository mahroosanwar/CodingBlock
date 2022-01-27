// In a number replace t digit by 9-t if no become mim

#include <iostream>
#include <cmath>
using namespace std;

long long int ChewbaccaAndNumber(long long int n){
    long long int num = 0, rem, place = 0;
    while(n!=0){
        
        rem = n%10;
        if(rem > 9-rem){                //for min
            if(rem==9 && (n/10)==0){        //for exclude starting 9
            //do nothing
            }
            else{
                rem = 9-rem;
            }
        }
        num = num + rem*pow(10,place);
        n/=10;
        place++;
    }
    return num;
}

int main(){
    long long int n;
    cin >> n;

    cout << ChewbaccaAndNumber(n);

    cout << endl;
    return 0;
}