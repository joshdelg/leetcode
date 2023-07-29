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
    bool checkSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr) {
            return root == subRoot;
        }

        return (root->val == subRoot->val) && checkSubtree(root->left, subRoot->left) && checkSubtree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // DFS to find matching root, then compare subtrees
        // In-order traversal: start from roots lowest down?
        
        // Base case: root is nullptr -> cannot be subtree
        if(root == nullptr) return false;

        // Compute left and right, then match root
        return checkSubtree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};