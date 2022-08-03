//HISTOGRAM

#include<iostream>
#include<stack>
using namespace std;

void maxRecAreaHistogram(int *hist, int n){
    // Create an empty stack. The stack holds indexes
    // of hist[] array. The bars stored in stack are
    // always in increasing order of their heights.
    stack<long long int> s;

    long long int area_with_top; // To store area with top bar
                       // as the smallest bar
    long long int maxArea = 0;
    long long int top;
    // Run through all bars of given histogram
    int i = 0;
    while(i<n){

        // If this bar is higher than the bar on top
        // stack, push it to stack
        if(s.empty() || hist[s.top()] <= hist[i]){
            s.push(i++);
        }

        // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'
        else{

            top = s.top();
            s.pop();

            if(s.empty()){
                area_with_top = hist[top]*i;
            }
            else{
                area_with_top = hist[top]*(i-s.top()-1);
            }
            
            //max area
            if(area_with_top>maxArea){
                maxArea = area_with_top;
            }
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (s.empty() == false)
    {
        top = s.top();
        s.pop();
        area_with_top = hist[top] * (s.empty() ? i : i - s.top() - 1);
 
        if (maxArea < area_with_top)
            maxArea = area_with_top;
    }
    cout << maxArea;
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    maxRecAreaHistogram(a, n);
    return 0;
}


// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.


// Input Format
// First line contains a single integer N, denoting the number of bars in th histogram.
// Next line contains N integers, ith of which, denotes the height of ith bar in the histogram.

// Constraints
// 1<=N<=10^6
// Height of each bar in histogram <= 10^10

// Output Format
// Output a single integer denoting the area of the required rectangle.

// Sample Input
// 5
// 1 2 3 4 5
// Sample Output
// 9
// Explanation
// The largest rectangle can be obtained of breadth=3 and length=3. Its starting index is 2 and ending index is 4 and it has a height of 3. Hence area = 3*3 = 9
