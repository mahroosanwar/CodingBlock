// Odd even Delhi

#include <iostream>
using namespace std;

void Odd_Even(int no){
    int even_sum = 0, odd_sum = 0;
    while(no!=0){

        int rem = no%10;
        if(no%2 == 0){
            even_sum = even_sum + rem;
        }
        else{
            odd_sum = odd_sum + rem;
        }
        no/=10;
    }
    if(odd_sum%3 == 0 || even_sum%4 == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){
    int n, no;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> no;
        Odd_Even(no);
    }

    cout << endl;
    return 0;
}


// Due to an immense rise in Pollution, Kejriwal is back with the Odd and Even Rule in Delhi. The scheme is as follows, each car will be allowed to run on Sunday if the sum of digits which are even is divisible by 4 or sum of digits which are odd in that number is divisible by 3. However to check every car for the above criteria can't be done by the Delhi Police. You need to help Delhi Police by finding out if a car numbered N will be allowed to run on Sunday?

// Input Format
// The first line contains N , then N integers follow each denoting the number of the car.

// Constraints
// N<=1000 Car No >=0 && Car No <=1000000000

// Output Format
// N lines each denoting "Yes" or "No" depending upon whether that car will be allowed on Sunday or Not !

// Sample Input
// 2
// 12345
// 12134
// Sample Output
// Yes
// No
// Explanation
// 1 + 3 + 5 = 9 which is divisible by 3
// 1 + 1 + 3 = 5 which is NOT divisible by 3 and 2+4 = 6 which is not divisble by 4.
