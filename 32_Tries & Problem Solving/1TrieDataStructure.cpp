//Trie Data Structure

#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;

    Node(char d) {
        data = d;
        terminal = false;
    }
};

class Trie{
    Node* root;
    int cnt;

public:

    Trie() {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(char *w) {

        Node *temp = root;
        for(int i=0; w[i] != '\0'; i++) {

            char ch = w[i];
            //if node is there we go to that node
            if(temp->children.count(ch)) {
                temp = temp->children[ch];
            }
            //if node is not there we create that node
            else {
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        //loop is over we are at the last node
        temp->terminal = true;
    }

    bool find(char *w) {
            Node* temp = root;

            for(int i=0; w[i] != '\0'; i++) {
                char ch = w[i];
                if(temp->children.count(ch) == 0) {
                    return false;
                }
                else {
                    temp = temp->children[ch];
                }
            }
            return temp->terminal;
        }
};

int main() {
    
    Trie t;
    char words[][10] = {"a","hello", "not", "news", "apple"};
    char w[10];
    cin >> w;

    for(int i=0; i<5; i++) {
        t.insert(words[i]);
    }

    if(t.find(w)) {
        cout << "Present";
    }
    else {
        cout << "Absent";
    }

    return 0;
}
