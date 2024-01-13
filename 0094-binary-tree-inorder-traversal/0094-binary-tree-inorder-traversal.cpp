/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// APPROACH 1 
// class Solution {
// private:
//     void orderTraversal(TreeNode* root, vector<int>& ans) {
//         // base case
//         if (root == nullptr) return;

//         // recursive call 
//         orderTraversal(root->left, ans);
//         ans.push_back(root->val);
//         // recursive call
//         orderTraversal(root->right, ans);
//     }

// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         orderTraversal(root, ans);
//         return ans;
//     }
// };


// APPROACH 2 :  Returning in recursive function itself

class Solution {
public:
    
    vector<int> helper(TreeNode* root) {
        vector<int> ans;
        
        if (root == NULL) return ans;

        // Traverse all the way to the left first
        vector<int> leftSubtree = helper(root->left);
        
        // Store the values of nodes in the left subtree
        ans.insert(ans.end(), leftSubtree.begin(), leftSubtree.end());
        
        // Store the value of the current node
        ans.push_back(root->val);
        
        // Traverse all the way to the right
        vector<int> rightSubtree = helper(root->right);
        
        // Store the values of nodes in the right subtree
        ans.insert(ans.end(), rightSubtree.begin(), rightSubtree.end());
        
        return ans;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        return helper(root);
    }
};
