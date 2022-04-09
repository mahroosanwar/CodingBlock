// First Non Repeating Character Implemenation

#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<char> q;
    int freq[27] = {0};

    char ch;
    cin >> ch;

    while(ch!='.') {
        //insert in q and freq table
        q.push(ch);
        freq[ch - 'a']++;

        // query
        //looking at front at the queue
        //and it is possible that the front element are not the once
        //frequency mauy be we need to continously pop the element 
        //from the front ubtil you get whose freq is one
        while(!q.empty()) {
            int idx = q.front() - 'a';      //index of the element at the front
            if(freq[idx]>1) {
                q.pop();
            }
            else{
                cout << q.front() << endl;
                break;
            }
        }

        //q is empty
        if(q.empty()){
            cout << -1 << endl;
        }
        cin >> ch;
    }
}