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
        int ans = INT_MIN;
    
        int dfs(TreeNode* node) {
            if (!node) return 0;
    
            // get left contribution
            int left = dfs(node->left);
            // get right contribution
            int right = dfs(node->right);
    
            left = max(0, left);
            right = max(0, right);
    
            ans = max(ans, node->val + left + right);
    
            return node->val + max(left, right);
        }
    
        int maxPathSum(TreeNode* root) {
            dfs(root);
            return ans;
        }
    };