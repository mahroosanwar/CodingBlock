// Vertical Order Print Binary Tree

#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void buildLevelOrder(node *&root) {
    int data;
    cin >> data;

    root = new node(data);
    queue<node *> q;
    q.push(root);

    while(!q.empty()) {
        node *f = q.front();
        q.pop();

        int left_data, right_data;
        cin >> left_data >> right_data;

        if(left_data != -1)  {
            f->left = new node(left_data);
            q.push(f->left);
        }

        if(right_data != -1) {
            f->right = new node(right_data);
            q.push(f->right);
        }
    }
}

// A utility function to find min and max distances with respect to root.
// min --> Minimum horizontal distance from root
// max --> Maximum horizontal distance from root
// hd  --> Horizontal distance of current node from root 
void findMinMax(node *root, int *min, int *max, int hd) {
    //base case
    if(root == NULL) {
        return;
    }

    //update the base case
    if(hd < *min) {
        *min = hd;
    }
    else if(hd > *max) {
        *max = hd;    
    }

    //rec case for left and right subtree
    findMinMax(root->left, min, max, hd-1);
    findMinMax(root->right, min, max, hd+1);
}

// A utility function to print all nodes on a given line_no.
void printVerticleLine(node *root, int line_no, int hd) {
    //base case
    if(root == NULL) {
        return;
    }

    if(hd == line_no) {
        cout << root->data << " ";
    }

    //rec case for left and right subtree
    printVerticleLine(root->left, line_no, hd-1);
    printVerticleLine(root->right, line_no, hd+1);
}

void verticleOrder(node *root) {
    // Find min and max distances with resepect to root
    int min = 0;
    int max = 0;
    findMinMax(root, &min, &max, 0);

    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodes line by line

    for(int line_no = min; line_no <= max; line_no++) {
        printVerticleLine(root, line_no, 0);
    }
}

int main() {
    int level;
    cin >> level;

    node *root = NULL;
    buildLevelOrder(root);

    verticleOrder(root);
    
    return 0;
}