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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.empty()) {
                return nullptr;
            }
            
            TreeNode* root = new TreeNode(preorder[0]);
    
            int rootIndex = 0;
            while (inorder[rootIndex] != root->val) {
                rootIndex++;
            }
    
            vector<int> leftInorder(
                inorder.begin(),
                inorder.begin() + rootIndex
            );
    
            vector<int> rightInorder(
                inorder.begin() + rootIndex + 1,
                inorder.end()
            );
    
            int leftSize = leftInorder.size();
    
            vector<int> leftPreorder(
                preorder.begin() + 1,
                preorder.begin() + 1 + leftSize
            );
    
            vector<int> rightPreorder(
                preorder.begin() + 1 + leftSize,
                preorder.end()
            );
    
            root->left = buildTree(leftPreorder, leftInorder);
            root->right = buildTree(rightPreorder, rightInorder);
    
            return root;
        }
    };

    //fast way is hashmap:
    /*
    class Solution {
    public:
        unordered_map<int, int> inorderIndex;

        TreeNode* build(
            vector<int>& preorder,
            int preLeft,
            int preRight,
            vector<int>& inorder,
            int inLeft,
            int inRight
        ) {
            if (preLeft > preRight) {
                return nullptr;
            }

            int rootVal = preorder[preLeft];
            TreeNode* root = new TreeNode(rootVal);

            int mid = inorderIndex[rootVal];
            int leftSize = mid - inLeft;

            root->left = build(
                preorder,
                preLeft + 1,
                preLeft + leftSize,
                inorder,
                inLeft,
                mid - 1
            );

            root->right = build(
                preorder,
                preLeft + leftSize + 1,
                preRight,
                inorder,
                mid + 1,
                inRight
            );

            return root;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            for (int i = 0; i < inorder.size(); i++) {
                inorderIndex[inorder[i]] = i;
            }

            return build(
                preorder,
                0,
                preorder.size() - 1,
                inorder,
                0,
                inorder.size() - 1
            );
        }
    };
    
    */