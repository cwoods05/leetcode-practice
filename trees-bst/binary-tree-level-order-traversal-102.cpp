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
        vector<vector<int>> levelOrder(TreeNode* root) {
            if (root == nullptr) return {};
    
            queue<TreeNode*> q;
            q.push(root);
            vector<vector<int>> levels;
    
            while (!q.empty()) {
                int levelSize = q.size();
                vector<int> curLevel;
                curLevel.reserve(levelSize);
    
                for(int i = 0; i < levelSize; ++i){
                    TreeNode* current = q.front();
                    q.pop();
    
                    curLevel.push_back(current->val);
    
                    if (current->left != nullptr) q.push(current->left);
                    if (current->right != nullptr) q.push(current->right);
                }
    
                levels.push_back(move(curLevel));
            }
    
            return levels;
    
        }
    };