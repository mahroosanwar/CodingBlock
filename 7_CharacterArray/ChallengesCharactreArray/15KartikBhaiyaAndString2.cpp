//Kartik Bhaiya And String

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//Function to count the length of window which can be made of char ch with <= k swaps
int CountMaxWindowSize(char a[], char ch, int k){
    int i=0; //left pointer
    int j=0; //right pointer
    int e = strlen(a) - 1;

    //First move the right pointer forward by k steps.
    //If the character is already ch , do not count a swap and move freely
    
    int cnt = 0; //Variable to count swap so far
    int ans = 0; //Variable to store final answer  
    for(j; cnt < k && j < e; j++){
        if(a[j] != ch){
            
            //If s[j] is not ch then count it as a swap and move forward
            
            cnt++;
        }

            //If no of swaps has reached k, stop moving j any more forward

        if(cnt == k){
            break;
        }
    }
    
    while(i<j){
        //Move j ahead if next element is ch as it doesn't count as a swap
        while(j < e && a[j+1] == ch){
            j++;
        }

        //Store the maximum length of all windows

        int currentlength = j - i + 1;
        ans = max(ans, currentlength);

        //Move left pointer by one to slide the window
        i++;

        //If the char at previous position of left pointer was not ch, then that position must
        //have counted as a swap earlier. Now we have a free swap available.
        //Iterate right pointer forward to use that one free swap

        if(j<=e && a[i-1] != ch){
            j++;
        }
    }

    return ans;
}

int main(){
    int k;
    cin >> k;
    cin.get();
    char a[100000];
    cin >> a;

        //If k is larger than s.size() then we can swap all the elements to either A or B
        //and obtain the answer equal to length of string
    if(k>=strlen(a)){
        cout << strlen(a);
        return 0;
    }
    //First let us check for longest perfect string of A's then we will find the same for B's and compare
    int ansForA = CountMaxWindowSize(a,'a',k);
    
    //Now we do the same for B's
    int ansForB = CountMaxWindowSize(a,'b',k);

    //Final answer is max of the two answers obtained above
    cout << max(ansForA, ansForB);

    return 0;
}




// You can solve this problem in O(n) time using the two pointer approach.

// Make two variabes , say i and j .
// i defines the beginning of a window and j defines its end.
// Start i from 0 and j from k.
// Let’s talk about the singular case when we are considering the max window for only 'a’s and consider only the swapping of b-> a. If we are able to get the answer for max window of consecutive 'a’s , we can simply implement the same algo for the max ‘b’ window as well.
// So we started i from 0 and j from k.
// Move j ahead freely as long as there are ‘a’ characters at s[ j ] position.
// Maintain a count variable which counts the number of swaps made or the number of 'b’s in our A window.
// If you encounter a ‘b’ char at s[ j ] position , increment the count variable. Count should never exceed k .
// Take the size of the window at every point using length = j - i + 1;
// Compute the max size window this way and do the same for ‘b’ as well.
// Output the maximum size window of ‘a’ and ‘b’.