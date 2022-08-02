//Calculate The Sum

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int CyclicArraySum(int a[], int n, int X,int f[]){
    
    
    for (int i = 0; i<n; i++){          

        if ((i-X)<0){                   //for index negative make change it with  
            a[i-X] = a[n-X+i];          //n-X index
            f[i] = a[i] + a[i-X];       //add as given in problem
        }
        else{
            f[i] = a[i] + a[i-X];       //add for all index and store in f[i]
        }
    }
    for(int i = 0; i<n; i++){
        a[i] = f[i];                    //update the a[i] with f[i]
    }
    return f[n];
}

int main(){
    
    int n ;
    cin >> n;

    int a[n], f[n] = {0};     //f is temp array to store

    for(int i = 0; i<n; i++){       // take array input
        cin >> a[i];
    }


    int Q,X;            //no of operation
    cin >> Q;

    for (int i = 0; i<Q; i++){      
        cin >> X;                   
        CyclicArraySum(a,n,X,f);        //for different value of X
    }
    
    for(int i = 0; i<n; i++){       //for Q is zero no value of X
        f[i] = a[i];
    }
    int sum = 0, ans;
    for(int i = 0; i<n; i++){
        sum += f[i];                    //sum in the last
    }
    ans = sum % (1000000007);

    cout << ans;

    cout << endl;
    return 0;
}


// Raj is a very smart kid who recently started learning computer programming. His coach gave him a cyclic array A having N numbers, and he has to perform Q operations on this array. In each operation the coach would provide him with a number X. After each operation, every element of the cyclic array would be replaced by the sum of itself and the element lying X positions behind it in the cyclic array. All these replacements take place simultaneously. For example, if the cyclic array was [a, b, c, d], then after the operation with X = 1, the new array would be [a+d, b+a, c+b, d+c]. He needs to output the sum of the elements of the final array modulus 10^9+7. He made a program for it but it's not very efficient. You know he is a beginner, so he wants you to make an efficient program for this task because he doesn't want to disappoint his coach.

// Input Format
// The first line of each test file contains a integer N. The next line contains N space separated integers which represent the elements of the cyclic array. The third line contains a integer Q representing the number of operations that will be applied to the array. Finally, Q lines follow, each one containing an integer X .

// Constraints
// 1 <= N <= 100000
// 1 <= Ai<= 10^9
// 0 <= Q <= 1000000
// 0 <= X < N

// Output Format
// Your program should output to the standard output stream the sum of the elements of the final array modulus 10^9+7.

// Sample Input
// 5
// 1 2 3 4 5
// 2
// 1
// 0
// Sample Output
// 60
// Explanation
// After the 1st operation (X = 1), the array would be [1+5, 2+1, 3+2, 4+3, 5+4] =[6, 3, 5, 7, 9]
// After 2nd operation (X = 0), the array would be [6+6, 3+3, 5+5, 7+7, 9+9] =[12, 6, 10, 14, 18]
// Thus the correct answer would equal to = (12+6+10+14+18) % (10^9+7) = 60
