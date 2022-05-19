// Tree top view

#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = right = NULL;
    }
};

node* buildLevelOrder() {
    int d;
    cin >> d;
    
    node* root = new node(d);
    queue<node*> q;

    q.push(root);

    while(!q.empty()) {
        node* f = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if(c1 != -1) {
            f->left = new node(c1);
            q.push(f->left);
        }

        if(c2 != -1) {
            f->right = new node(c2);
            q.push(f->right);
        }
    }
    return root;
}

vector<int> topView(node* root) {
    vector<int> ans;
    
    //base case
    if(root == NULL) {
        return ans;
    }

    map<int, int> m;        //line(horizontal distance from root) and data
    queue<pair<node*, int> >q;

    q.push({root, 0});
    while(!q.empty()) {
        
        auto it = q.front();
        q.pop();

        //get the top most node of from queue
        node *temp = it.first;
        //get the top most line no. from queue
        int line = it.second;

        //if that line no doesn't exist in the map
        //then initilize the node in that map
        if(m.find(line) == m.end()) {
            m[line] = temp->data;
        } 

        if(temp->left != NULL) {
            q.push({temp->left, line - 1});
        }

        if(temp->right != NULL) {
            q.push({temp->right, line + 1});
        }
    }

    for(auto it : m) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {

    node *root = buildLevelOrder();

    vector<int> v = topView(root);

    for(auto it : v) {
        cout << it << " ";
    } 

    return 0;
}

// time comp. : O(n);
// space comp : O(n); 

// https://youtu.be/Et9OCDNvJ78
