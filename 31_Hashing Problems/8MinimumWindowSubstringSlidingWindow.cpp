//Minimum Window Substring (Sliding Window) 

#include<iostream>
#include<climits>
#include<string>
using namespace std;

string find_window(string s, string pat) {
    int SL = s.length();
    int PL = pat.length();

    //1. corner Case
    if(PL > SL) {
        return "None";
    }

    //2. Freq Maps
    int FS[256] = {0};      //Freq arrays for String
    int FP[256] = {0};      //Freq arrays for pattern

    for(int i=0; i<PL; i++) {
        char ch = pat[i];
        FP[ch]++;
    }

    //3. Sliding window (Expension & Contraction + Update the Min length window)
    int cnt = 0;        //cnt stores the total count of character that matched
    int start = 0;      //left pointer for shrinking the window 
    int min_len = INT_MAX;
    int start_idx = -1;
    for(int i=0; i<SL; i++) {
        char ch = s[i];
        FS[ch]++;

        //Maintain the cnt of characters matched
        if(FP[ch] != 0 and FS[ch] <= FP[ch]) {
            cnt++;
        }

        //if all the character match
        if(cnt == PL) {
            //start shrinking the window

            char temp = s[start];
            //lop to remove all unwanted character the window
            while(FP[temp] == 0 or FS[temp] > FP[temp]) {
                //just ignore the current char 
                //we gonna reduce its frequency
                FS[temp]--;
                start++;
                temp = s[start];
            }

            //window size
            int window_len = i - start + 1;
            if(window_len < min_len) {
                min_len =  window_len;
                start_idx = start; 
            }  
        }
    }
    if(start_idx == -1) {
        return "None";
    }
    string ans = s.substr(start_idx, min_len);

    return ans;
}

int main() {

    string s = "heelloaeo world";
    string p = "eelo";

    cout << find_window(s, p) << endl;

    return 0;
}