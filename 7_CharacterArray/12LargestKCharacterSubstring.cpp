// largest k unique character substring length

#include <iostream>
#include <algorithm>
using namespace std;

void largestKUnique(char a[], int k){
    int freq[26] = {0};
    int cnt =0;
    int len = -1;
    int i=0;

    for(int j=0; a[j] !='\0'; j++){
        freq[a[j] - 'a']++;
        if(freq[a[j] - 'a'] == 1){
            cnt++;
        }

        while(cnt > k){
            //here we have more than k unque charactor
            //so shrunk the window
            freq[a[i] - 'a']--;
            if(freq[a[i] - 'a'] == 0){
                cnt--;
            }
            i++;
        }

        if(cnt == k){
            len = max(len, j-i+1);
        }
    }
    cout << "Largest string length " << k << " Unique Charactor"<< " --> " << len << endl;
}

int main(){
    char a[] = "abbceddd";
    int k;
    cin >> k;

    largestKUnique(a,k);

    cout << endl;
    return 0;
}