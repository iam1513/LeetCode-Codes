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
// public:

//     bool validOrNot(TreeNode* root,long minVal, long maxVal){

//         if(root == NULL) return true;
//         // Root val should lie in a range
//         if(root->val <= minVal || root->val >= maxVal){ // Also values can be equal, depends on contraint
//             return false;
//         }

// // Right and left subtrees should be BST
//         return validOrNot(root->left,minVal,root->val) && validOrNot(root->right,root->val,maxVal);
//     }

//     bool isValidBST(TreeNode* root) {
        
//         return validOrNot(root,LONG_MIN, LONG_MAX);
//     }
// };


// APPROACH 2 : Inorder traversal and vector
// class Solution {
// public:

//     void orderTraversal(TreeNode* root, vector<int> &ans){
//         if(root == NULL) return ;

//         orderTraversal(root->left,ans);
//         ans.push_back(root->val);
//         orderTraversal(root->right,ans);

//     }

//     bool isValidBST(TreeNode* root) {
//         vector<int> ans;
//         orderTraversal(root,ans);

//         for(int i = 0; i < ans.size() - 1; i++){
//             if(ans[i]>=ans[i+1]){
//                 return false;
//             }
//         }

//         return true;
//     }
// };

// APPROACH 3 : Inorder traersal without using vector
class Solution {
public:
    bool orderTraversal(TreeNode* root, TreeNode* &prev) {
        if (root == NULL) return true;

        if (!orderTraversal(root->left, prev)) {
            return false;
        }

        if (prev != NULL && prev->val >= root->val) {
            return false;
        }

        prev = root;

        return orderTraversal(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return orderTraversal(root, prev);
    }
};
