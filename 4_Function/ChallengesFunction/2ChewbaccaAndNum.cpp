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


// Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

// Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

// Input Format
// The first line contains a single integer x (1 ≤ x ≤ 10^18) — the number that Luke Skywalker gave to Chewbacca.

// Constraints
// x <= 100000000000000000

// Output Format
// Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

// Sample Input
// 4545
// Sample Output
// 4444
// Explanation
// There are many numbers form after inverting the digit. For minimum number, check if inverting digit is less than or greater than the original digit. If it is less, then invert it otherwise leave it.
