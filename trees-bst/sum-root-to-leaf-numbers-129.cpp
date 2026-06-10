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
        /*vector<int> nums = {};
    
        void helper(TreeNode* root){
            if (!root->left && !root->right) nums.push_back(root->val);
            
            if (root->left){
                int left = stoi(to_string(root->val) + to_string(root->left->val));
                root->left->val = left;
                helper(root->left);
            }
    
            if (root->right){
                int right = stoi(to_string(root->val) + to_string(root->right->val));
                root->right->val = right;
                helper(root->right);
            }
        }
    
        int sumNumbers(TreeNode* root) {
            if (!root) return 0;
    
            helper(root);
    
            int sum = 0;
            for (int i = 0; i < nums.size(); ++i){
                sum += nums[i];
            }
    
            return sum;
    
        }*/
    
    
        int dfs(TreeNode* root, int cur) {
            if (!root) return 0;
    
            cur = cur * 10 + root->val;
    
            if (!root->left && !root->right) {
                return cur;
            }
    
            return dfs(root->left, cur) + dfs(root->right, cur);
        }
    
        int sumNumbers(TreeNode* root) {
            return dfs(root, 0);
        }
    };