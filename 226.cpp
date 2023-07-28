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
    TreeNode* invertTree(TreeNode* root) {
        // Recursive solution, switch left and right subtrees
        // Base case: If empty, just return
        if(root == nullptr) return nullptr;

        // Invert left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        // Switch left and right nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};