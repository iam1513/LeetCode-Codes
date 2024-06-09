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
class Solution {
public:
    void helper(TreeNode* root, int currentNumber, int& sum) {
        if (root == NULL) return;

        currentNumber = currentNumber * 10 + root->val; // At each level , we have to multiply by 10

        if (root->left == NULL && root->right == NULL) {
            sum += currentNumber;
        }

        helper(root->left, currentNumber, sum);
        helper(root->right, currentNumber, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
};
