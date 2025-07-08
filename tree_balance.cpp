#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (i < nodes.size() && !q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

int height(TreeNode* node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(TreeNode* root) {
    if (!root) return true;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return abs(leftHeight - rightHeight) <= 1 && 
           isBalanced(root->left) && 
           isBalanced(root->right);
}

int main() {
    // This would receive input from the frontend in a real implementation
    // For testing, you can use hardcoded values or command line input
    
    vector<string> nodes = {"1", "2", "3", "4", "5", "null", "7"};
    TreeNode* root = buildTree(nodes);
    
    if (isBalanced(root)) {
        cout << "The tree is height-balanced." << endl;
    } else {
        cout << "The tree is not height-balanced." << endl;
    }
    
    return 0;
}