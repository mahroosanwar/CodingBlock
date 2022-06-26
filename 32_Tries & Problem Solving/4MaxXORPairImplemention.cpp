// Tries 4 - Max Xor Pair Implementation

#include<iostream>
using namespace std;

class node{
public:
    node *left;     //for 0
    node *right;    //for 1
};

class trie{
    node *root;
public:
    trie() {
        root = new node();
    }

    //insert fun
    void insert(int n) {
        node *temp = root;
        for(int i=31; i>=0; i--) {
            int bit = (n>>i)&1;
            if(bit==0) {
                //check if the left node exist or not
                if(temp->left == NULL) {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            //if bit is 1
            else{
                //check if the right node exist or not
                if(temp->right ==  NULL) {
                    temp->right = new node();
                }
                temp = temp->right;
            } 
        }
    }

    //helper function to find max XOR
    //to find the max XOR that we can make using this perticular
    //value from the already present no's in Tries
    int max_xor_helper(int value) {
        int current_ans = 0;
        node *temp = root;
        for(int j=31; j>=0; j--) {
            int bit = (value>>j)&1;

            if(bit == 0) {
                //find the complementry value
                if(temp->right != NULL) {
                    temp = temp->right;
                    current_ans += (1<<j); 
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                //if current bit is 1 
                //try to find the node in which 0 is present bcz current value is 1 
                if(temp->left != NULL) {
                    temp = temp->left;
                    current_ans += (1<<j);
                }
                else {
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    //take input array and size
    int max_xor(int *input, int n) {
        int max_xor = 0;

        for(int i=0; i<n; i++) {
            int val = input[i];
            insert(val);
            int current_xor = max_xor_helper(val);
            cout << current_xor << " ";
            max_xor = max(current_xor, max_xor);
        }
        return max_xor;
    }
};

int main() {

    //max XOR pair
    int input[] = {3, 10, 5, 25, 2, 8};
    int n = sizeof(input)/sizeof(int);

    trie t;
    
    cout << t.max_xor(input, n) << endl;

    return 0;
}