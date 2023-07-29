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
    int maxDepth(TreeNode* root) {
        // Pre-order Iterative DFS Solution w/ Stack:
        if(root == nullptr) return 0;

        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int result = 0;
        while(!s.empty()) {
            // Process node
            pair<TreeNode*, int> p = s.top();
            s.pop();
            result = max(result, p.second);

            // Add children
            TreeNode* node = p.first;
            if(node->right != nullptr) s.push({node->right, p.second + 1});
            if(node->left != nullptr) s.push({node->left, p.second + 1});
        }

        return result;
        
        // // Iterative BFS solution:
        // queue<TreeNode*> q;
        // if(root != nullptr) q.push(root);
        // int result = 0;

        // while(!q.empty()) {
        //     // Traverse all nodes at this queue level
        //     int nodes = q.size(); // Variable so value doesn't change
        //     for(int i = 0; i < nodes; i++) {
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if(node != nullptr) {
        //             if(node->left != nullptr) q.push(node->left);
        //             if(node->right != nullptr )q.push(node->right);
        //         }
        //     }
        //     // Finished all nodes at this level, so add 1
        //     result++;
        // }

        // return result;
        
        // // Recursive DFS solution:
        // // Check left and right, return 1 + max nodes traversed, 0 if null
        
        // if(root == nullptr) return 0;

        // return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};