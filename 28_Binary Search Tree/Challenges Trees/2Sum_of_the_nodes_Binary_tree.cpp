//Sum of the nodes (Binary tree)

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
        left  = NULL;
        right = NULL;
    }
};

//build recursively nodes first all left then right
void buildTree(node *&root) {    
    int data;
    cin >> data;

    root = new node(data);

    string isleftPresent, isrightPresent;
    
    cin >> isleftPresent;
    if(isleftPresent == "true") {
        buildTree(root->left);
    }

    cin >> isrightPresent;
    if(isrightPresent == "true") {
        buildTree(root->right);
    }
}

int sum_of_Nodes(node *root) {
    //base case
    if(root == NULL) {
        return 0;
    }

    if(root->left == NULL && root->right == NULL) {
        return root->data;
    }

    //rec case
    int sumLeft = sum_of_Nodes(root->left);
    int sumRight = sum_of_Nodes(root->right);

    int totalSum = sumLeft + sumRight + root->data;

    return totalSum;
}

int main() {

    node *root = NULL;

    buildTree(root);

    int sum = sum_of_Nodes(root);
    cout << sum << endl;

    return 0;
}

// Given a binary tree find sum of all the nodes.

// Input Format
// Enter the value of the node then the Boolean choice i.e whether the node has a left child , then enter the left child's data . The input acts in a recursive manner i.e when the left child's children are made only then we move onto the parent's right child

// Constraints
// None

// Output Format
// Display the sum of all the nodes

// Sample Input
// 50 true 25 true 12 false false false true 75 true 62 false false false
// Sample Output
// 224
// Explanation
// If we enter the following values

// 50 true 25 true 12 false false false true 75 true 62 false false false

// the tree would look like :

// 25 => 50 <= 75

// 12 => 25 <= END

// END => 12 <= END

// 62 => 75 <= END

// END => 62 <= END
