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
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (!root) return false;
    
            targetSum = targetSum - root->val;
    
            if (!root->left && !root->right){
                if (targetSum == 0) return true;
                return false;
            }
    
            //bool left = false;
            //bool right = false;
    
            //if (root->left) left = hasPathSum(root->left, targetSum);
            //if (root->right) right = hasPathSum(root->right, targetSum);
    
            return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
        }
    };