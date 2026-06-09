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
        int bestDiameter;
    
        int helper(TreeNode* root) {
            if(root == nullptr) return 0;
    
            int leftHeight = helper(root->left);
            int rightHeight = helper(root->right);
    
            bestDiameter = max(bestDiameter, leftHeight + rightHeight);
    
            return 1 + max(leftHeight, rightHeight);
        }
    
        int diameterOfBinaryTree(TreeNode* root) {
            if (root == nullptr) return 0;
    
            bestDiameter = 0;
    
            helper(root);
    
            return bestDiameter;
    
        }
    };